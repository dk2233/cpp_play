# Nie wyświetlamy potwierdzeń przy przeładowaniu
set confirm off
set trace-command on
echo on
#set disassembly-flavor intel  # Opcjonalnie: format Intela jest czytelniejszy
define diag1
    printf "--- Diagnostyka Funkcji ---\n"
    # Wyświetla adres i plik/linię
    i args
    info line
     frame
    disassemble $pc, +20 
    printf "Adres w rejestrze PC: %p\n", $pc
    printf "---------------------------\n"
end

define diag_copy 
    printf "--- Kopiowanie obiektu ---\n"
    i args
    printf "Adres nowego obiektu (this): %p\n", this
    #printf "Adres źródła (other):        %p\n", &$arg0
    # Wyświetl backtrace, aby wiedzieć, kto wymusił kopię
    where 2
end



start


break var_class::var_class(var_class const&)
commands $bpnum
    printf "\nstart of copy construct\n"
    diag1
    i function var_class
    diag_copy
    si 

end

b var_class_heap

commands $bpnum
    printf "\ncall of var_class_heap\n"
    
    diag1
end



i b 
i proc mappings
c
c
c
n
p/x vars_heap_copy
p *vars_heap_copy
p vars


#printf "adres of base class that is copied %p \n", $adr_base



