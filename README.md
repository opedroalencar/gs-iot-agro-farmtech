# 🚜 FarmTech Solutions - Sistema de Irrigação Inteligente (Fase 2)

## 👥 Grupo 56 - Integrantes

| Nome | RM |
| :--- | :--- |
| **Lucas Michels Kuntz** | 570050 |
| **João Pedro Ferreira Alencar** | 573473 |
| **Camila Duarte Ferreira** | 569629 |
| **Thiago Henrique Piva Balerio** | 572194 |
| **Alisson Vinicius de Souza Rabelo Teixeira** | 573512 |

## 👩‍🏫 Corpo Docente
* **Tutor:** Edson de Oliveira
* **Coordenador:** André Godoi

## 📝 Descrição do Projeto
Este projeto faz parte da Fase 2 da startup **FarmTech Solutions**. O objetivo é criar um dispositivo IoT robusto para monitorar as condições do solo em plantações de **Cana-de-Açúcar** e automatizar o processo de irrigação de forma eficiente e sustentável.

O sistema utiliza um microcontrolador **ESP32** para coletar dados de sensores (simulados) e tomar decisões em tempo real sobre a ativação de uma bomba d'água, garantindo que a planta receba água apenas quando as condições de pH e nutrientes forem ideais para a absorção.

## 🛠️ Hardware e Componentes (Wokwi)
Para esta simulação, utilizamos as seguintes substituições didáticas:
- **ESP32**: Unidade central de processamento.
- **Sensor DHT22**: Utilizado para monitorar a **Umidade do Solo**.
- **LDR (Photoresistor)**: Mapeado via software para simular um **Sensor de pH** (Escala 0-14).
- **3 Botões Verdes**: Simulam os níveis de **Nitrogênio (N)**, **Fósforo (P)** e **Potássio (K)**.
- **Módulo Relé (Azul)**: Representa o acionamento da **Bomba de Irrigação**.

## ⚙️ Lógica de Ativação
A bomba de irrigação (Relé) só é ativada se **todas** as seguintes condições forem atendidas:
1. **Déficit Hídrico**: Umidade do solo abaixo de **50%**.
2. **Faixa de pH Ideal**: pH entre **5.5 e 7.5** (calibrado para Cana-de-Açúcar).
3. **Presença de Nutrientes**: Sensores de N, P e K devem acusar sinal positivo (Botões ativados).

> **Nota Técnica:** No arquivo `diagram.json`, configurei os botões no modo **Toggle (Retenção)**. Isso permite que os botões fiquem pressionados sem a necessidade de manter o mouse clicado, simulando uma leitura constante de sensores de fluxo de nutrientes.

## 📁 Arquivos do Repositório
- `main.ino`: Código-fonte em C++ com a lógica do sistema.
- `diagram.json`: Configuração física dos componentes e fiação no Wokwi.
- `circuito_print.png`: Captura de tela do esquema elétrico.

## 🔗 Demonstração
- **Link do Simulador (Wokwi):** https://wokwi.com/projects/461745355378525185
- **Vídeo de Demonstração (YouTube):** https://youtu.be/tcN-1n5QhW4
