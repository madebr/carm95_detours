#!/usr/bin/env python3 -u

import sys
import os

# Generates declarations to use in carm95_inject
# Usage: find /path/to/dethrace/src/DETHRACE -name "*.c" | xargs generator.py > output.txt

ida_map_file_path = '/Users/jeff/Downloads/Carma_Win95.map'

#typedef int(__cdecl* tGetOpponentsSectionMaxSpeed)(tOpponent_spec* pOpponent_spec, tS16 pSection, int pTowards_finish);
#static tGetOpponentsSectionMaxSpeed GetOpponentsSectionMaxSpeed = (tGetOpponentsSectionMaxSpeed)0x0040BE6E;

func_map = {}
gv_map = {}

func_offset = int('0x00401000', 16)
gv_offset = int('0x00507000', 16)

def read_map_file():
    global gv_map
    global func_map

    f = open(ida_map_file_path, 'r')

    while True:
        line = f.readline()
        if line == '':
            break

        line = line.strip()
        if line.startswith('0001:'):
            parts = [s for s in line[5:].split(' ') if s]
            # map function name to virtual address
            effective_address = hex(int(parts[0], 16) + func_offset)
            func_map[parts[1]] = effective_address
        elif line.startswith('0003:'):
            parts = [s for s in line[5:].split(' ') if s]

            # skip over most autogenerated stuff
            if parts[1].startswith('g'):
                # map global variable name to virtual address
                effective_address = hex(int(parts[0], 16) + gv_offset)
                gv_map[parts[1]] = effective_address


read_map_file()

for file_name in sys.argv[1:]:
    # print (file_name)
    # continue

    f = open(file_name, 'r')

    in_gvs = True

    while True:
        line = f.readline()
        if line == '':
            break        

        if '(' in line and ')' in line:
            # found functions
            in_gvs = False

        if in_gvs:
            if line == '\n' or line.startswith('#') or line.startswith('/') or line.startswith(' ') or line.startswith('}') or line.startswith('{') or line.startswith('extern'):
                continue

            parts = line.split(' ', 2)
            idx = parts[1].find('[')
            indices = -1
            if idx != -1:
                name = parts[1][:idx]
                end_idx = parts[1].find(']')
                indices_part = parts[1][idx+1:end_idx]
                if indices_part != '':
                    indices = int(indices_part)
            else:
                # strip last 2 chars ";\n"
                name = parts[1][:-2]
            
            if name in gv_map:
                if indices == -1:
                    print('HOOK_VARIABLE_IMPLEMENT(%s, %s, %s);' % (parts[0], name, gv_map[name]))
                else:
                    print('HOOK_VARIABLE_IMPLEMENT_ARRAY(%s, %s, %s, %s);' % (parts[0], name, indices, gv_map[name]))

            #HOOK_VARIABLE_IMPLEMENT(int, gFrame_period_for_this_munging, 0x12345678);
        else:
            if line[0] != ' ' and '(' in line and ')' in line and line[-2] == '{' and 'typedef' not in line:
                line = line.strip()
                parts = line.split(' ',  1)
                ret = parts[0]
                parts = parts[1].split('(', 1)
                name = parts[0]
                args = parts[1].replace(' {', ';')
                # print(ret, "--", name, "--", args)

                if name in func_map:
                    print('typedef %s(__cdecl* t%s)(%s' % (ret, name, args))
                    print('static t%s %s = (t%s)%s;' % (name, name, name, func_map[name]));
                

    # outF = open(file_name, "w")
    # outF.writelines(lines)
    # outF.close()

        



