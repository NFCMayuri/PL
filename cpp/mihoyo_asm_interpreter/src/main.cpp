#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#define CMD_COUNT 12
const char *cmd_str[CMD_COUNT] = {"moo", "mOo", "moO", "mOO", "Moo", "MOo",
                                  "MoO", "MOO", "OOO", "MMM", "OOM", "oom"};

void moo(std::vector<int> &cmd, int &cmd_offset, std::vector<int> &memory,
         int &memory_offset, int &reg);
void mOo(std::vector<int> &cmd, int &cmd_offset, std::vector<int> &memory,
         int &memory_offset, int &reg);
void moO(std::vector<int> &cmd, int &cmd_offset, std::vector<int> &memory,
         int &memory_offset, int &reg);
void mOO(std::vector<int> &cmd, int &cmd_offset, std::vector<int> &memory,
         int &memory_offset, int &reg);
void Moo(std::vector<int> &cmd, int &cmd_offset, std::vector<int> &memory,
         int &memory_offset, int &reg);
void MOo(std::vector<int> &cmd, int &cmd_offset, std::vector<int> &memory,
         int &memory_offset, int &reg);
void MoO(std::vector<int> &cmd, int &cmd_offset, std::vector<int> &memory,
         int &memory_offset, int &reg);
void MOO(std::vector<int> &cmd, int &cmd_offset, std::vector<int> &memory,
         int &memory_offset, int &reg);
void OOO(std::vector<int> &cmd, int &cmd_offset, std::vector<int> &memory,
         int &memory_offset, int &reg);
void MMM(std::vector<int> &cmd, int &cmd_offset, std::vector<int> &memory,
         int &memory_offset, int &reg);
void OOM(std::vector<int> &cmd, int &cmd_offset, std::vector<int> &memory,
         int &memory_offset, int &reg);
void oom(std::vector<int> &cmd, int &cmd_offset, std::vector<int> &memory,
         int &memory_offset, int &reg);
typedef void (*cmd_func)(std::vector<int> &cmd, int &cmd_offset,
                         std::vector<int> &memory, int &memory_offset,
                         int &reg);
cmd_func cmd_address[CMD_COUNT] = {moo, mOo, moO, mOO, Moo, MOo,
                                   MoO, MOO, OOO, MMM, OOM, oom};
;
void moo(std::vector<int> &cmd, int &cmd_offset, std::vector<int> &memory,
         int &memory_offset, int &reg) {
  while (true) {
    if (!strcmp(cmd_str[cmd[--cmd_offset]], "MOO"))
      break;
  }
  cmd_offset++;
}
void mOo(std::vector<int> &cmd, int &cmd_offset, std::vector<int> &memory,
         int &memory_offset, int &reg) {
  memory_offset++;
  memory.push_back(0);
  cmd_offset++;
}
void moO(std::vector<int> &cmd, int &cmd_offset, std::vector<int> &memory,
         int &memory_offset, int &reg) {

  memory_offset--;
  cmd_offset++;
}
void mOO(std::vector<int> &cmd, int &cmd_offset, std::vector<int> &memory,
         int &memory_offset, int &reg) {
  if (!strcmp(cmd_str[memory[memory_offset]], "mOO") ||
      memory[memory_offset] < 0 || memory[memory_offset] > CMD_COUNT)
    exit(1);
  cmd_func cmd_a = cmd_address[memory[memory_offset]];
  cmd_a(cmd, cmd_offset, memory, memory_offset, reg);
}

void Moo(std::vector<int> &cmd, int &cmd_offset, std::vector<int> &memory,
         int &memory_offset, int &reg) {
  char tmp_a;
  if (memory[memory_offset] == 0) {
    std::cin >> tmp_a;
    memory[memory_offset] = tmp_a;
  } else {
    tmp_a = memory[memory_offset];
    std::cout << tmp_a;
  }
  cmd_offset++;
}
void MOo(std::vector<int> &cmd, int &cmd_offset, std::vector<int> &memory,
         int &memory_offset, int &reg) {
  memory[memory_offset]--;
  cmd_offset++;
}
void MoO(std::vector<int> &cmd, int &cmd_offset, std::vector<int> &memory,
         int &memory_offset, int &reg) {

  memory[memory_offset]++;
  cmd_offset++;
}
void MOO(std::vector<int> &cmd, int &cmd_offset, std::vector<int> &memory,
         int &memory_offset, int &reg) {
  if (memory[memory_offset] == 0) {
    while (true) {
      if (!strcmp(cmd_str[++cmd_offset], "moo"))
        break;
    }
    cmd_offset++;
  }
}
void OOO(std::vector<int> &cmd, int &cmd_offset, std::vector<int> &memory,
         int &memory_offset, int &reg) {
  memory[memory_offset] = 0;
  cmd_offset++;
}
void MMM(std::vector<int> &cmd, int &cmd_offset, std::vector<int> &memory,
         int &memory_offset, int &reg) {
  if (reg != 0) {
    reg = memory[memory_offset];
  } else {
    memory[memory_offset] = reg;
    reg = 0;
  }
  cmd_offset++;
}
void OOM(std::vector<int> &cmd, int &cmd_offset, std::vector<int> &memory,
         int &memory_offset, int &reg) {
  std::cout << memory[memory_offset];
  cmd_offset++;
}
void oom(std::vector<int> &cmd, int &cmd_offset, std::vector<int> &memory,
         int &memory_offset, int &reg) {
  std::cin >> memory[memory_offset];
  cmd_offset++;
}
int main() {
  std::vector<int> cmd;
  std::vector<int> memory(1);
  int reg = 0;
  int tmp;
  size_t i, j;
  char tmp_cmd[4];
  tmp_cmd[3] = 0;
  int cmd_offset = 0, memory_offset = 0;
  while (true) {
    if ((tmp_cmd[0] = getchar()) != '\n') {
      tmp_cmd[1] = getchar();
      tmp_cmd[2] = getchar();
      for (i = 0; i < CMD_COUNT; i++) {
        if (!strcmp(tmp_cmd, cmd_str[i])) {
          cmd.push_back(i);
          break;
        }
      }
    } else
      break;
  }
  while (cmd_offset < cmd.size()) {
    cmd_func cmd_a = cmd_address[cmd[cmd_offset]];
    cmd_a(cmd, cmd_offset, memory, memory_offset, reg);
  }
}
