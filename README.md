# Philosophers


**Philosophers** è un progetto della **42 School** che esplora i concetti di **programmazione concorrente** e **gestione dei thread**. Il progetto si basa sul classico problema dei filosofi a cena, una metafora utilizzata per descrivere le sfide di sincronizzazione in ambienti concorrenti.

## 🧐 Problema dei filosofi a cena

Cinque filosofi siedono attorno a un tavolo circolare. Ogni filosofo alterna momenti di **pensiero** e **mangiare**. Per mangiare, un filosofo deve raccogliere due forchette (una alla sua sinistra e una alla sua destra). Tuttavia, ci sono solo cinque forchette sul tavolo, e ciascuna forchetta è condivisa tra due filosofi adiacenti.

### Obiettivi del progetto
- Simulare il problema dei filosofi a cena utilizzando **thread**.
- Gestire correttamente la sincronizzazione per evitare situazioni di:
  - **Deadlock** (quando i filosofi rimangono bloccati in attesa delle forchette).
  - **Race condition** (accesso non sincronizzato alle risorse condivise).
- Ottimizzare le prestazioni e garantire che ogni filosofo abbia la possibilità di mangiare.

---

## 🔑 Concetti chiave
- **Mutua esclusione**: Garantire che solo un filosofo alla volta possa accedere a una forchetta.
- **Thread**: Ogni filosofo è rappresentato da un thread separato.
- **Mutex**: Utilizzati per sincronizzare l'accesso alle risorse condivise.
- **Sincronizzazione**: Coordinare i thread per evitare problemi di deadlock.

---
## ⚙️ Requisiti e Compilazione

### Requisiti

Per compilare ed eseguire il progetto **Philosophers**, assicurati di avere i seguenti strumenti installati:

- **GCC**: Un compilatore compatibile con il progetto.
- **Make**: Per automatizzare la compilazione.
- **Pthread**: La libreria standard per la gestione dei thread in C.

## 🚀 Esecuzione

**Avvio del programma:**
   Dopo aver compilato il progetto, esegui l'eseguibile `philo` specificando il numero di filosofi e i parametri richiesti.

   **Comando:**
   ```
   ./philo <numero_filosofi> <tempo_morire> <tempo_mangiare> <tempo_dormire> [numero_pasti]
   ```
Parametri:

- <numero_filosofi>: Numero di filosofi (e forchette).
- <tempo_morire>: Tempo massimo (in millisecondi) che un filosofo può aspettare prima di morire.
- <tempo_mangiare>: Tempo (in millisecondi) necessario per mangiare.
- <tempo_dormire>: Tempo (in millisecondi) necessario per dormire.
- [numero_pasti] (opzionale): Numero minimo di pasti che ogni filosofo deve consumare.

Comando:
```
./philo 5 800 200 200
Esempio di output:
1 1 is thinking
2 2 is eating
3 3 is eating
4 4 is sleeping
5 5 is thinking
```
> Note sull'esecuzione:
  I filosofi iniziano a pensare e cercano di prendere le forchette vicine per mangiare.
  Dopo aver mangiato, il filosofo entra in stato di dormire.
  Il ciclo continua finché il programma non raggiunge il numero opzionale di pasti (se specificato) o viene terminato manualmente.

## 🛠️ Debug e Test

### Test delle configurazioni
Puoi verificare il comportamento del programma con diverse configurazioni di parametri per simulare vari scenari.

1. **Esempio di test base:**
   Esegui il programma con una configurazione semplice:
   ```
   ./philo 5 800 200 200
5 filosofi.
800 ms come tempo massimo prima che un filosofo muoia.
200 ms per mangiare.
200 ms per dormire.
Test con il numero minimo di pasti: Per verificare che ogni filosofo completi un numero minimo di pasti:
```
./philo 5 800 200 200 3
Ogni filosofo deve mangiare almeno 3 volte.
```
Deadlock:

Un deadlock si verifica quando i filosofi rimangono bloccati perché tutti stanno aspettando una forchetta.
Verifica che il tuo programma eviti questa situazione, ad esempio aumentando il numero di filosofi:

> ./philo 10 800 200 200
Tempi critici:

Simula un ambiente con tempi molto ristretti:
- ./philo 5 200 100 100
In questa configurazione, i filosofi potrebbero morire rapidamente se il programma non gestisce correttamente i thread.
Monitoraggio delle risorse
Per monitorare l'utilizzo delle risorse di sistema durante l'esecuzione:

CPU e memoria: Usa top o htop per osservare l'utilizzo:
- `top`
Thread attivi: Verifica i thread creati dal programma:
- `ps -T -p $(pidof philo)`
Strumenti di debug
GDB (GNU Debugger): Per tracciare eventuali problemi di runtime:

Valgrind: Per rilevare problemi di gestione della memoria:

Il programma dovrebbe gestire correttamente i seguenti errori:

Parametri invalidi:

./philo 0 800 200 200
Output atteso:

Errore: Numero di filosofi non valido.
Mancanza di risorse: Se il sistema non può creare thread o allocare memoria, dovrebbe mostrare un messaggio di errore chiaro.

