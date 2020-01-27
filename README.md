# temperature-monitor-arduino
Projeto para monitoração de temperatura ambiente e de um objeto (sendo o objetivo de identificar a temperatura de uma pessoa), utilizando dispositivos eletrônicos facilmente encontráveis e Arduino. 

O funcionamento se baseia no sensor infravermelho de temperatura MLX90615, que  é capaz de detectar temperaturas do objeto na direção do sensor e do ambiente.
Através do sensor, do display OLED, de LEDs e do microcontrolador Arduino buscou-se detectar temperaturas corporais e apontar possíveis sintomas de febre e hipertermia, como também indicar temperaturas normais.
Checou-se que o sensor funciona bem apontado na região das axilas e da testa, e foi utilizada incerteza de 0.5 graus na lógica para condizer com o datasheet do sensor de temperatura.

As imagens do funcionamento, como também as bibliotecas utilizadas e alguns testes dos dispositivos se encontram em pastas separadas. A imagem da montagem no fritzing e os parâmetros de temperatura utilizados também se encontram presentes.
