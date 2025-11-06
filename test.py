file=open("out.txt","r")

content=file.readlines()
for line in content:
    # remove extra lines
# line 0


# line 1
# line 2
# line 3
# line 4
    line=line.strip()
    if line:
        line_count = len(content)
        print(f"Line {line_count}: {line}")
        word_count = len(line.split())
        char_count = len(line)
        print(f"Words: {word_count}, Characters: {char_count}")
        

        
        
        
    
file.close()