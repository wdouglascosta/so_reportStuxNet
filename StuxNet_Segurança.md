# StuxNet
#### William Douglas Costa Silva - RA 89239

> <p align="center">
> "Um protótipo funcional e temível de uma cyber-arma que <br>
> dará início a uma nova corrida armamentista no mundo."
</p>

## Introdução
Em novembro de 2010 o governo iraniano declarou que algumas centrífugas de enriquecimento de urânio do programa nuclear nacional haviam sido danificadas, e um vírus havia infectado os computadores pessoais da usina. Esse ataque, em conjunto com outros ataques do mesmo gênero, pode ser considerado o inicio de uma guerra cibernética com potencial para tornar-se uma grande preocupação para os governos de todo o mundo.

Foi descoberto em junho de 2010, e é o primeiro worm descoberto que espiona e reprograma controladores de processos industriais. O StuxNet é capaz de reprogramar CLP's (Controladores Lógicos Programáveis) e esconder as alterações. O virus pode estar camuflado em mais de 100 mil computadores, porém para usuários comuns o worm é inofensivo, só funciona efetivamente em computadores que executem um sistema muito específico de centrífugas de enriquecimento de urânio iranianas, visto que cada usina possui particularidades muito bem definidas.

## StuxNet - Uma Visão Geral
Stuxnet é um vírus sofisticado desenvolvido para atacar apenas um sistema específico SCADA (do inglês *"Supervisory Control and Data Acquisition"*), que é um sistema de controle de processos industriais.

Ele faz uso de quatro vulnerabilidades *zero-day*, que é uma brecha de segurança no sistema ainda desconhecida pelos programadores.

Também faz uso de *rootkits*, que são técnicas avançadas para se auto camuflar dos usuários e de programas anti malwares do Windows. Faz uso de duas certificações digitais roubadas que assinam seus drivers. Além disso, seus desenvolvedores precisaram de um grande conhecimento sobre os sistemas alvo.

É muito aceito que este worm tenha sido desenvolvido para atacar especificamente o programa nuclear iraniano, visto que os ataques condizem perfeitamente com a planta de enriquecimento de urânio de Natanz.
Uma indicação de que o Stuxnet visava o programa nuclear do Irã é que ele só tem como alvo instalações que com um certo layout físico muito específico. O layout das centrífugas em uma instalação como Natanz é chamado de cascata, isso descreve como as centrífugas são conectadas. Neste caso as centrífugas dentro de um estágio são conectadas em paralelo.
Um fato interessante é que em 2008 o presidente do Irã Ahmadinejad visitou a planta de Natanz, e fotos dessa visita foram publicadas em um site, e em uma destas fotos era possível ver a tela de um sistema supervisório que mostrava a estrutura em cascata da então chamada *IR-1*, com base nessa informação era possível identificar o número de centrífugas em cada estágio, o que combina exatamente com a estrutura do código do StuxNet

O programa nuclear iraniano foi lançado por volta de 1950, criando armas fora do programa *Atoms for Peace* dos Estados Unidos. Houve um atraso graças a revolução de 1979 e depois por causa da guerra contra o Iraque. Mesmo assim os líderes iranianos estavam interessados em continuar com o programa nuclear, e começaram a obter ajuda de outros países para avançar.

Em 2002, um grupo de oposição iraniano revelou publicamente duas instalações nucleares não declaradas no Irã, admitindo ter construído instalações para enriquecimento de combustível e produção de água pesada ostensivamente para uso em reatores de pesquisa. O governo suspendeu seus planos em 2003, mas retomou em 2006 argumentando que tinha o direito de estabelecer seu próprio programa de enriquecimento de urânio.

O Irã mantém seu programa completamente em paz, porém a Agência Internacional de Energia Nuclear (IAEA) insiste que o Irã não cumpre com os requisitos de segurança, o que foi motivo de diversas sanções do Conselho de Segurança contra o 