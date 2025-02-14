%include "includes/win/typedef.inc"
%include "includes/win/winuser.inc"

extern MessageBoxA
extern GetLastError
extern ExitProcess

extern glGetError

%ifnmacro mMessageBoxA 
    %macro mMessageBoxA 3
        mov     rcx, NULL
        lea     rdx, [rel %2]
        lea     r8, [rel %1]
        mov     r9, %3
        call    MessageBoxA
    %endmacro
%endif

%ifnmacro wfatal_error 
    %macro wfatal_error 2
        call            GetLastError
        mov             rbx, rax
        mMessageBoxA    %1, %2,  MB_ICONEXCLAMATION | MB_OK
        mov             rcx, rbx
        call            ExitProcess
    %endmacro
%endif

%ifnmacro wglfatal_error 
    %macro wglfatal_error 2
        call            glGetError
        mov             rbx, rax
        mMessageBoxA    %1, %2,  MB_ICONEXCLAMATION | MB_OK
        mov             rcx, rbx
        call            ExitProcess
    %endmacro
%endif
