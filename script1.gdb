# startup.gdb
file moj
break main
start

# Definicja "skrótu" do rzutowania węzła - jak komenda w Trace32
define pn
  print ((std::_Rb_tree_node<std::string> *)$arg0)->_M_value_field
end

# Automatyczne pokazywanie aktualnej instrukcji i stosu
display /i $pc
display /4xg $rsp

# Przejdź do konkretnego miejsca, które Cię interesuje
break containers
continue

