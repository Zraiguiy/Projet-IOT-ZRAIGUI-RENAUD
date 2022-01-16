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

![carte_lora](https://user-images.githubusercontent.com/97834284/149670722-30d899a7-5acf-4402-bc62-4a5ade11cbff.jpg)

![carte_pui](https://user-images.githubusercontent.com/97834284/149670727-b3e66869-0b5c-4c8f-a1a1-6e8804345985.jpg)



# Cout 
* Kit de développement LoRa : 25€
* Carte STM32f0discovery : 10€
* Buzzer électronique : 5€
* Cout pour 5000 unités produites : 40 x 5000 = 200 000€

# Cout certifications
* Certification ETSI pour les universités, organismes publics de recherche et associations d'utilisateurs à but non lucratif : 2000 €
* Certification LoRa Alliance : 10 000 €/an pour obtenir accès au programme d'affiliation pour la certification
* Cout de la certification produit : 1000 € par produit
* Il faudrait estimer un total de 13 000 € pour notre produit.

# Implémentation du logiciel embarqué de l’objet défini
# Format LPP des messages LoRaWAN uplink et downlink
# logiciel embarqué de l’objet sirène
# Métriques logiciel du logiciel embarqué
* Nombre de ligne de codes : 150
* Taille fichier binaire : 45.4 kB 
# Durée de vie 
*La carte LoRa peut supporter 2 batteries AA 3V, chaque batterie ayant une capacite de 1500 mAh.
*La carte a pour but de détecter un changement brutal de température et d'informer au plus vite la personne concernée, on a donc décidé de fixer un temps d'échantillonnage de 20 secondes.
*On a fixé le datarate a 5, ce qui équivaut à un facteur de propagation SF7 et une bande passante de 125KHz, on obtient avec ce paramètre un débit binaire de 5470 bit/s
![LoRaWAN-data-rates](https://user-images.githubusercontent.com/97834284/149666636-e4c14749-fa6d-48b2-8946-4f301ccd5fe1.png)
En entrant ces paramètres dans le calculateur de batterie ci-dessous, on obtient une durée de vie pour la batterie aux alentours de 292 jours. Cependant, le calculateur se base sur un produit qui contient en plus d'un détecteur de température, un détecteur de CO2 et un accéléromètre. Notre alarme devrait donc théoriquement durer plus longtemps.

![batterie](https://user-images.githubusercontent.com/97834284/149666301-6448f49d-da12-49de-be1a-cd0e97465412.png)


# Analyse du cycle de vie
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
