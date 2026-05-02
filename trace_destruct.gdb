# Nie wyświetlamy potwierdzeń przy przeładowaniu
set confirm off
#set disassembly-flavor intel  # Opcjonalnie: format Intela jest czytelniejszy
define diag1
    printf "--- Diagnostyka Funkcji ---\n"
    # Wyświetla adres i plik/linię
    i args
    info line
     frame
    disassemble $pc, +40 
    printf "Adres w rejestrze PC: %p\n", $pc
    printf "---------------------------\n"
end

# Ustawiamy breakpoint na funkcji (zmień 'moja_funkcja' na docelową)
break ~var_class

# Definiujemy listę komend dla powyższego breakpointu (zawsze dla ostatniego numeru)
commands 1 
silent 
diag1

end

# Uruchomienie programu
run
c
c


