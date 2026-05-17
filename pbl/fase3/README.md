# 🚜 FarmTech Solutions - Banco de Dados Relacional (Fase 3)

## 📝 Descrição da Etapa
Esta etapa consistiu na persistência, estruturação e validação dos dados históricos de sensores agrícolas, utilizando a infraestrutura do banco de dados relacional **Oracle**. O ecossistema foi desenhado para suportar a volumetria analítica da cultura de **Cana-de-Açúcar**, garantindo consistência com os parâmetros IoT desenvolvidos anteriormente.

## 📁 Arquivos desta Pasta
- `Sensores_Fazenda.csv`: Base de dados estruturada utilizada para a carga inicial.
- `consultas.sql`: Script contendo a query de extração e validação de consistência.
- `print_banco.png.jpeg`: Evidência física da execução bem-sucedida no servidor.

## 📊 Saneamento de Dados e Regras de Negócio
Durante a execução do assistente de importação no Oracle SQL Developer, foram aplicadas as seguintes correções de modelagem física para mitigar falhas críticas de banco:
- **Restrição de Sintaxe:** As colunas originais `soil_moisture_%` e `humidity_%` foram renomeadas para `SOIL_MOISTURE_PRC` e `HUMIDITY_PRC`, contornando a proibição de caracteres especiais no dicionário de dados do Oracle.
- **Tipagem Cronológica:** Os campos de data e marca de tempo foram mapeados como `VARCHAR2(50)` para evitar o truncamento de strings e erros de máscara de leitura (`ORA-01861`).

## 💻 Consulta de Validação (Query SQL)
A persistência e a integridade das linhas foram validadas no servidor da FIAP através da instrução abaixo:

```sql
SELECT * FROM SENSORES_FAZENDA;
