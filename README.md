# SensorThread
Thread no arduino<br><br>
O Arduino não suporta tarefas paralelas "REAL" (também conhecido como Threads), mas podemos usar esta biblioteca para melhorar nosso código 
e agendar facilmente tarefas com tempo fixo (ou variável) entre execuções.

Esta Biblioteca ajuda a manter organizada e a facilitar o uso de múltiplas tarefas. Podemos usar Interrupções de Temporizadores e torná-lo realmente poderoso, executando tarefas de "pseudo-fundo" sob o tapete.

Por exemplo, eu uso pessoalmente para todos os meus projetos e coloco toda a aquisição e filtragem de sensores dentro dele, deixando o loop 
principal, apenas para lógica e parte "legal". 

By: <a href="https://github.com/ivanseidel/ArduinoThread">Ivan Seidel</a>
