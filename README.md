# WireGuard Management Center (WGMC)

Le WGMC est une application Web qui permet de distribuer dynamiquement les configurations WireGuard afin d'ajouter ou révoquer des pairs. Il permet également de superviser les tunnels WireGuard en affichant leur état et le nombre d'octets reçus et transmis.
Il utilise la version 1.0.0, légèrement modifiée, de l'outil [wg-api].

[wg-api]: https://github.com/jamescun/wg-api

![Schéma architecture WGMC](wg-management-center/src/assets/schemaArchitectureWGMC.png)



## Configuration

### wg-api-twisted

Il doit être installé sur le **serveur central** avec l'adresse du **localhost** et le port **2222**.

```sh
./wg-api-twisted --device=wg0 --listen=127.0.0.1:2222
```

Il doit être installé sur les **appareils WireGuard** avec l'adresse de l'**endpoint** et le port **1111**.

```sh
./wg-api-twisted --device=wg0 --listen=X.X.X.X:1111
```

### WGMC

L'outil WGMC doit être installé sur le **serveur central**.

Dans un premier temps, il faut lancer le serveur de la base de données de l'outil json-server.

```sh
npm run db:serve
```

Dans un second temps, il faut lancer le serveur de l'application Web Vuejs.

```sh
npm run serve
```

Par défaut, la **base de données** se trouve à l'adresse **127.0.0.1:3001** et l'**interface Web** à l'adresse **127.0.0.1:8080**.


## Utilisation du WGMC

Pour établir un tunnel de télégestion entre votre appareil WireGuard et le serveur central, vous devez :

* 
  Ajouter le WGMC comme nouveau pair dans le fichier de configuration *wg0.conf* de votre appareil.

* 
  Ajouter votre appareil WireGuard au WGMC en cliquant sur le bouton *New Device* situé en haut à droite de l'interface Web.

Une fois le tunnel de télégestion établi, vous pouvez gérer votre appareil WireGuard depuis le WGMC en ajoutant/supprimant ddes pairs.
