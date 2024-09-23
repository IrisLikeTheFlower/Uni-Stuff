def split_string(s, length):
    return [s[i:i+length] for i in range(0, len(s), length)]

class MemoryManager:
    def __init__(self, num_cells, max_per_line):
        self.num_cells = num_cells
        self.max_per_line = max_per_line
        self.allocated_blocks = []
        self.free_blocks = [(0, 0, num_cells)]
        self.next_block_id = 0

    def allocate(self, num_cells):
        for i, (o, start, size) in enumerate(self.free_blocks):
            if size >= num_cells:
                self.allocated_blocks.append((self.next_block_id, start, num_cells))
                print(f"{start}")
                self.next_block_id += 1

                if size == num_cells:
                    del self.free_blocks[i]
                else:
                    self.free_blocks[i] = (0, start + num_cells, size - num_cells)
                return

        print("Not Enough Memory")

    def free(self, block_id):
        for i, (id, start, size) in enumerate(self.allocated_blocks):
            if (start== block_id):
                del self.allocated_blocks[i]

                self.free_blocks.append((0, start, size))
                self.free_blocks.sort()

                print(f"Block {block_id} freed")
                return

        print(f"Block {block_id} not found")

    def print_memory(self):
        line = ''

        all_blocks = sorted(self.allocated_blocks + self.free_blocks, key=lambda x: x[1])

        for current_block in all_blocks:
            if current_block in self.allocated_blocks:
                if len(str(current_block[1])) == 1:
                    line += str(current_block[1]) + 'x'
                else:
                    line += str(current_block[1])
                line += 'x' * (current_block[2] - 2) * 2 + 'x|'
            else:
                line += '  ' * current_block[2]

        memory = split_string(line, self.max_per_line * 2)

        for segment in memory:
            print(f'|{segment}|')

    def print(self):
        print(self.num_cells)
        print(self.max_per_line)
        print(self.allocated_blocks)
        print(self.free_blocks)
        print(self.next_block_id)

def main():
    num_cells = int(input("Memory: "))
    max_per_line = int(input("Row length: "))

    manager = MemoryManager(num_cells, max_per_line)

    print("Enter 'help' to see commands")

    while True:
        command = input().strip().split()
        if len(command) == 0:
            continue

        cmd = command[0]

        if cmd == "allocate":
            if len(command) < 2 or not command[1].isdigit():
                print("Wrong command. Correct: allocate <num>")
            else:
                manager.allocate(int(command[1]))
        elif cmd == "free":
            if len(command) < 2 or not command[1].isdigit():
                print("Wrong command. Correct: free <id>")
            else:
                manager.free(int(command[1]))
        elif cmd == "print":
            manager.print_memory()
        elif cmd == "printdev":
            manager.print()
        elif cmd == "exit":
            break
        elif cmd == "help":
            print("""Commands:
   allocate <num> - allocate <num> cells of memory
   free <id> - free block with first cell number <id>
   print - print memory blocks map
   exit - exit this program""")
        else:
            print("Unknown command, print 'help' to get info")


if __name__ == "__main__":
    main()
