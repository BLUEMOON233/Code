.686
.model flat, stdcall
option casemap :none ;�رմ�Сд

;######################################
include windows.inc
include kernel32.inc
include shlwapi.inc
includelib kernel32.lib
includelib shlwapi.lib
;######################################

.data
    prompt1        db "�������һ�����֣�", 0
    prompt2        db "������ڶ������֣�", 0
    prompt3        db "��������������֣�", 0
    isTriangleMsg  db "�����������ܹ���һ�������Ρ�", 13, 10, 0
    notTriangleMsg db "���������ֲ��ܹ���һ�������Ρ�", 13, 10, 0
    errorMsg       db "������Ч�����������롣", 0
    buffer         db 16 dup(0)
    _insize        dd ?
    outhandle      dd ?
    inhandle       dd ?
    side           dd 3 dup(0)

.code
IsTriangle proc
    mov edx, side
    add edx, side + 4
    cmp edx, side + 8
    jle notTriangle

    mov edx, side
    add edx, side + 8
    cmp edx, side + 4
    jle notTriangle

    mov edx, side + 4
    add edx, side + 8
    cmp edx, side
    jle notTriangle

    jmp isTriangle
    
isTriangle:
    mov ebx, 1
    ret
    
notTriangle:
    mov ebx, 0  
    ret
    
IsTriangle endp

main proc
    ; ��ȡ��׼������
    invoke GetStdHandle, STD_OUTPUT_HANDLE
    mov    outhandle, eax
    invoke GetStdHandle, STD_INPUT_HANDLE
    mov    inhandle, eax
    
    lea esi, side
    ; ��ȡ��һ������
    invoke WriteConsole, outhandle, addr prompt1, sizeof prompt1 - 1, 0, 0
    invoke ReadConsole, inhandle, addr buffer, sizeof buffer, addr _insize, 0
    invoke StrToInt, addr buffer
    mov side, eax ;
    
    ; ��ȡ�ڶ�������
    invoke WriteConsole, outhandle, addr prompt2, sizeof prompt2 - 1, 0, 0
    invoke ReadConsole, inhandle, addr buffer, sizeof buffer, addr _insize, 0
    invoke StrToInt, addr buffer
    mov side + 4, eax ;
    
    ; ��ȡ����������
    invoke WriteConsole, outhandle, addr prompt3, sizeof prompt3 - 1, 0, 0
    invoke ReadConsole, inhandle, addr buffer, sizeof buffer, addr _insize, 0
    invoke StrToInt, addr buffer
    mov side + 8, eax

    
    ; �����ӳ����ж��Ƿ񹹳�������
    push edx
    call IsTriangle
    pop edx
    cmp ebx, 1
    je yes
    cmp ebx, 0
    je no
    
    ; ������
    yes:
    invoke WriteConsole, outhandle, addr isTriangleMsg, sizeof isTriangleMsg - 1, 0, 0
    jmp endProgram
    
    no:
    invoke WriteConsole, outhandle, addr notTriangleMsg, sizeof notTriangleMsg - 1, 0, 0
    jmp endProgram
    
    endProgram:
    ret
main endp
    
start:
    mov ecx, 10

again:
    push ecx
    call main
    pop ecx

    loop again

    invoke ExitProcess, 0
    end start