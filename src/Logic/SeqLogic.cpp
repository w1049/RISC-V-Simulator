//
// Created by w10493 on 2023/2/2.
//

#include <iostream>
#include "SeqLogic.h"
#include "../Utils/Instruction.h"

SeqLogic::SeqLogic() = default;

void SeqLogic::compute() {
    // Attention topological order
    u32 branch = 0;
    u32 memRead = 0;
    u32 memToReg = 0;
    u32 aluOp0 = 0;
    u32 aluOp1 = 0;
    u32 memWrite = 0;
    u32 aluSrc = 0;
    u32 regWrite = 0;
    u32 imm = 0;

    rom.address = pc.out;
    u32 instruction = rom.instruction();
    std::cout << "PC = " << pc.out / 4 << std::endl;

    switch (Instruction::opcode(instruction)) {
        case 0b0110011: // R
            regWrite = 1;
            aluOp1 = 1;
            break;
        case 0b0000011: // ld
            aluSrc = 1;
            memToReg = 1;
            regWrite = 1;
            memRead = 1;
            imm = Instruction::Iimm(instruction);
            break;
        case 0b0100011: // sd
            aluSrc = 1;
            memWrite = 1;
            imm = Instruction::Simm(instruction);
            break;
        case 0b1100011: // beq
            branch = 1;
            aluOp0 = 1;
            imm = Instruction::SBimm(instruction);
            break;
    }

    // instruction + pc = new pc
    reg.read_register1 = Instruction::rs1(instruction);
    reg.read_register2 = Instruction::rs2(instruction);

    reg.reg_write = regWrite;
    reg.write_register = Instruction::rd(instruction);

    alu.in1 = reg.read_data1();
    if (aluSrc) alu.in2 = imm;
    else alu.in2 = reg.read_data2();
    switch ((aluOp1 << 1) + aluOp0) {
        case 0b00:
            alu.op = 0b0010;
            break;
        case 0b01:
            alu.op = 0b0110;
            break;
        case 0b10:
            switch (Instruction::funct3(instruction)) {
                case 0b000:
                    if (Instruction::get(instruction, 30, 30)) alu.op = 0b0110;
                    else alu.op = 0b0010;
                    break;
                case 0b111:
                    alu.op = 0b0000;
                    break;
                case 0b110:
                    alu.op = 0b0001;
                    break;
            }
    }

    memory.address = alu.out();
    memory.write_data = reg.read_data2();
    memory.mem_write = memWrite;
    memory.mem_read = memRead;
    if (memToReg) reg.write_data = memory.read_data();
    else reg.write_data = alu.out();

    u32 pcSrc = branch & alu.zero();
    if (pcSrc) pc.in = pc.out + (imm << 1);
    else pc.in = pc.out + 4;

}
