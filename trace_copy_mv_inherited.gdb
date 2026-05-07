# Nie wyświetlamy potwierdzeń przy przeładowaniu
set confirm off
#do we need to see every commands?
set trace-command off

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

define diag_copy 
    printf "--- Kopiowanie obiektu ---\n"
    i args
    printf "Adres nowego obiektu (this): %p\n", this
    #printf "Adres źródła (other):        %p\n", &$arg0
    # Wyświetl backtrace, aby wiedzieć, kto wymusił kopię
    where 2
end



start
break var_class_mv_test

commands $bpnum
    printf "call test function \n"
    diag1
end

break var_class_mv::var_class_mv(const var_class& base)
commands $bpnum
    printf "call copy construct in var_class_mv \n"
    diag1
    p/x vars
    set $adr_base = &vars
    p/x &vars
end




i b 
c
n


    diag1

    p/x vars
    p/x vars_mv
    printf "adres of base class that is copied %p \n", $adr_base
#set $i=0
#while $i++<10
#diag1
#si 
#end
# Definiujemy listę komend dla powyższego breakpointu (zawsze dla ostatniego numeru)
#commands 1 
#silent 
#diag1
#end

# Uruchomienie programu


