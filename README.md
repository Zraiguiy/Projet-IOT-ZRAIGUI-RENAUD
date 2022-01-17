# Projet IOT
#### Réalisé par ZRAIGUI Yassir et RENAUD Virgil 
Lors de ce projet, nous avons dû réaliser une alarme connectée au réseau LoRaWAN.

Pour cela nous avions à disposition une carte LoRaWAN ainsi qu'un documentation approfondie sur les différentes méthodes nécessaires à la réalisation du projet.

# Architecture globale
LoRaWAN est un protocole de communication utilisant la radio afin de connecter des objets à bas débit.
Pour cela, LoRaWAN utilise la technologie radio LoRa. Cette technologie se base sur le "Chirp spreading spectrum", une modulation en fréquence très robuste contre le bruit, le multipath et l'effet doppler. Cette modulation est effectuée sur des bandes de fréquences publiques dont l'accès est règlementé selon la région. ![Chirp — Wikipédia](https://upload.wikimedia.org/wikipedia/commons/thumb/c/cf/Linear-chirp.svg/1200px-Linear-chirp.svg.png)

Notre alarme utilisera la technologie LoRa afin de communiquer avec un server ChirpStack. Ce serveur récolte les données envoyées par notre carte et nous informe de leur arrive ou non grâce a un journal.

Enfin, on peut rediriger ces données vers l'application Cayenne. Cette application web permet d'afficher les données voulues sur un site web, permettant ainsi de facilement observer l'arrivée de données.

# Sécurité globale
Afin de sécuriser la transmission des données, une clé est créée lors de la configuration du Chirpstack.

En effet, dès l'enregistrement de notre carte dans la base de donnée du server, on obtient une "AppKey" qui sera nécessaire a la connexion et la programmation de la carte LoRaWAN.

# Architecture matérielle

Ci-dessous la composition de la carte LoRa-E5-Dev Board utilisée. Ce qui nous a intéressé pour ce projet était : 
1. Le bouton utilisateur 
2. Les ports GPIO 
3. Les LEDS



![lora_detais](https://user-images.githubusercontent.com/97834284/149724657-2adb6d90-9792-4f28-83c7-193573ccd5b6.png)

![carte_lora](https://user-images.githubusercontent.com/97834284/149670722-30d899a7-5acf-4402-bc62-4a5ade11cbff.jpg)

La carte flash stm32f0discovery inclue une carte de prototypage permettant de connecter facilement des composants et modules supplémentaire. Elle permet aussi de réaliser le débuggage et le flashage de la carte LoRa.


![carte_pui](https://user-images.githubusercontent.com/97834284/149670727-b3e66869-0b5c-4c8f-a1a1-6e8804345985.jpg)



# Cout 
Le calcul du coût est très approximatif. Les prix utilisés ci-dessous sont ceux trouvés sur des sites vendeurs pour des individus. On considérera donc que si le but est de vendre en grande quantité, l'achat en masse devrait revenir moins chère. Ainsi on serait capable de réaliser un bénéfice malgré que celui-ci ne soit pas pris en compte dans le calcul.
* Kit de développement LoRa : 25€
* Carte STM32f0discovery : 10€
* Buzzer électronique : 5€
* Coût d'une unité et prix de vente : 40 €
* Cout pour 5000 unités produites : 40 x 5000 = 200 000€

# Cout certifications
Afin de pourvoir mettre en ventre notre produit, il est nécessaire d'obtenir plusieurs certification permettant de réglementer celui-ci en plus de certifié sa qualité. La ceretification ETSI (European Telecommunications Standards Institute) a pour but de produire les normes de télécommunications qui seront utilisées dans toute l'Europe. La certification LoRa Alliance permet d'obtenir ceertains avantages qu'un membre de l'alliance LoRa aurait. Un de ces avantages est de pouvoir obtenir une certification pour un produit LoRa. Ci-dessous les coût de ces certifications :

* Certification ETSI pour les universités, organismes publics de recherche et associations d'utilisateurs à but non lucratif : 2000 €
* Certification LoRa Alliance : 10 000 €/an pour obtenir accès au programme d'affiliation pour la certification
* Cout de la certification produit : 1000 € par produit
* Il faudrait estimer un total de 13 000 € pour notre produit.


# Métriques logiciel du logiciel embarqué

* Nombre de ligne de codes : 150 lignes
* Taille fichier binaire : 45.4 kB 
# Démonstration du programme


# Durée de vie 
* La carte LoRa peut supporter 2 batteries AA 3V, chaque batterie ayant une capacite de 1500 mAh.
* La carte a pour but de détecter un changement brutal de température et d'informer au plus vite la personne concernée, on a donc décidé de fixer un temps d'échantillonnage de 20 secondes.
* On a fixé le datarate a 5, ce qui équivaut à un facteur de propagation SF7 et une bande passante de 125KHz, on obtient avec ce paramètre un débit binaire de 5470 bit/s
![LoRaWAN-data-rates](https://user-images.githubusercontent.com/97834284/149666636-e4c14749-fa6d-48b2-8946-4f301ccd5fe1.png

En entrant ces paramètres dans le calculateur de batterie ci-dessous, on obtient une durée de vie pour la batterie aux alentours de 292 jours. Cependant, le calculateur se base sur un produit qui contient en plus d'un détecteur de température, un détecteur de CO2 et un accéléromètre. Notre alarme devrait donc théoriquement durer plus longtemps.

![batterie](https://user-images.githubusercontent.com/97834284/149666301-6448f49d-da12-49de-be1a-cd0e97465412.png)


# Analyse du cycle de vie

Afin de réaliser une ACV, il faut suivre 4 étapes :
* __Cadrer la démarache__ : Notre produit devra fonctionner sans arrêt pendant une longue période de temps,
il est donc nécessaire de réaliser une ACV afin de s'assurer que celi-ci sera le moins nuisible et polluant au possible.
* __Collecter les données__ : En entrée de notre système, on aura deux batteries AA 3V et en sortie des signaux radio
* __Faire l'inventaire__ : Une carte électronique est principalement composée de cuivre, un matériau recyclable, les batteries utilisées le sont pas. De même, le buzzer utilisé peut facilement être rercyclé. En sortie, seulement des signaux radio sont produites et rare sont les cas ou ceux-ci peuvent être nuisible.
* __Inrerpréter__ : Le produit n'est donc pas forcément polluant. Les problèmes que l'on pourrait recontrer serait l'abandon du produit ou son oubli. Pour résoudre se problème on pourrait ajouter envoyer un message à l'utilisateur vers la fin de vie de l'objet. On pourrait aussi remaplacer les piles par des piles rechargeables afin d'améliorer encore plus le cycle de vie du produit.
![acv](https://user-images.githubusercontent.com/97834284/149724973-f9c4cfd1-eda8-4c96-abd2-c27562b9817c.png)


# Comparaison

| Produit |Cout|Durée de vie batterie|Sécurité |Température|CO2|Humidité|Mouvement
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|Notre Alarme|40€|1 an| AppKey |Oui|Non|Non|Non
|SmartVOX® | ??? |∞* | ???|Non|Non|Non|Non
|R602A LoRaWAN Wireless Siren|179 €|5 ans| Encrypt-RF™ Security|Non|Non|Non|Non
|ACS Switch Buzz®| ??? | 5 ans |???| Non|Non|Non|Oui
|MClimate|160 €| 10 ans | End-to-End encryption (AES-CTR)|Oui|Oui|Oui|Non


∞ = alimentation secteur

# Conclusion

Malgré une alarme assez minimaliste, nous avons réussi à détecter la température, envoyer l'information au Chirpstack qui la renvoie vers Cayenne. Les signaux sonores et lumineux s'activent dès le changement brusque de température ou l'appui du bouton. Nous avons appris les bases de l'internet des objets et avons compris le fonctionnement des différents aspects permettant la mise en route d'un objet connecté, que ce soit matériel ou logiciel.
