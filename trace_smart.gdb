# Nie wyświetlamy potwierdzeń przy przeładowaniu
set confirm off
#do we need to see every commands?
set trace-command off
echo on
#set disassembly-flavor intel  # Opcjonalnie: format Intela jest czytelniejszy
define diag1
    printf "--- Diagnostyka Funkcji ---\n"
    # Wyświetla adres i plik/linię
    i args
    info line
     frame
     where 2
    disassemble $pc, +20 
    printf "Adres w rejestrze PC: %p\n", $pc
    printf "---------------------------\n"
end




start
break smart_ptr

commands $bpnum
    printf "call new class\n"
    diag1
end




i b 
start
