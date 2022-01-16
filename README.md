# Projet IOT
#### Realise par ZRAIGUI Yassir et RENAUD Virgil 
Lors de ce projet, nous avons du realise une alarme connecte en LoRaWAN.

Pour cela nous avions a disposition une carte LoRaWAN ainsis qu'un documentation appronfondie sur les differentes methodes necessaires a la realisation du projet.

# Architecture globale
LoRaWAN est un protocole de communication utilisant des radio afin de connecte des objets a bas debit.
Pour cela, LoRaWAN utilise la technologie radio LoRa. Cette technologie se base sur le "Chirp spreading spectrum" une modulation en frequence tres robuste contre le bruit, le multipath et l'effet doppler. Cette modulation est effectue sur des bandes de frequences publiques dont l'acces est reglementer selon la region. ![Chirp — Wikipédia](https://upload.wikimedia.org/wikipedia/commons/thumb/c/cf/Linear-chirp.svg/1200px-Linear-chirp.svg.png)

Notre alarme utilisera la technologie LoRa afin de communiquer avec un server ChirpStack. Ce serveur recoltre les donnees envoyee par notre carte et nous informe de leur arrive ou non grace a un journal.

Enfin, on peut rediriger ces donnees vers l'application Cayenne. Cette application web permet d'afficher les donnees voulu sur un site web, permettant ainsi de facilement observer l'arrivee de donnees.

# Securite globale
Afin de securiser la transmission des donnees, une cle est cree lors de la configuration du Chirpstack.

En effet, des l'enregistrement de notre carte dans la base de donnee du server, on obtient une "AppKey" qui sera necessaire a la connection et la programmation de la carte LoRaWAN.

# Architecture materielle

Ci-dessous la composition de la carte LoRa-E5-Dev Board utilisee. Ce qui nous a interesse  pour ce projet etaient : 
1. Le boutton utilisateur 
2. Les ports GPIO 
3. Les LEDS
![carte_lora](https://user-images.githubusercontent.com/97834284/149670722-30d899a7-5acf-4402-bc62-4a5ade11cbff.jpg)

![carte_pui](https://user-images.githubusercontent.com/97834284/149670727-b3e66869-0b5c-4c8f-a1a1-6e8804345985.jpg)

![carte_pui](https://user-images.githubusercontent.com/97834284/149661169-570fde21-30ee-4b36-89a1-b74b495b00a9.jpg)


# Cout 
* Kit de developpement LoRa : 25€
* Carte STM32f0discovery : 10€
* Buzzer electronique : 5€
* Cout pour 5000 unite produite : 40 x 5000 = 200 000€

# Cout certifications
* Certification ETSI pour les universités, organismes publics de recherche et associations d'utilisateurs à but non lucratif : 2000 €
* Certification LoRa Alliance : 10 000 €/an pour obtenir acces au programme d'affiliation pour la certification
* Cout de la certification produit : 1000 € par produit
* Il faudrait estimer un total de 13 000 € pour notre produit.

# Implémentation du logiciel embarqué de l’objet défini
# Format LPP des messages LoRaWAN uplink et downlink
# logiciel embarqué de l’objet sirène
# Métriques logiciel du logiciel embarqué
* Nombre de ligne de codes : 150
* Taille fichier binaire : 45.4 kB 
# Duree de vie 
*La carte LoRa peut supporter 2 batteris AA 3V, chaque batterie ayant une capacite de 1500 mhA
*La carte a pour but de detecter un chagement brutale de temperature et d'informer au plus vite la personne concernee, on a donc decider de fixer un temps d'echantillonage de 20 secondes.
*On a fixer la datarate a 5, ce qui equivaut a un facteur de propagation SF7 et une bande passante de 125KHz, on obtinet avec ce parametre un debit binaire de 5470 bit/s
![LoRaWAN-data-rates](https://user-images.githubusercontent.com/97834284/149666636-e4c14749-fa6d-48b2-8946-4f301ccd5fe1.png)
En entrant ces parametres dans le calculateur de batterie ci-dessous, on obtient une duree de vie pour la batterie aux alentours 292 jours. Cependant, le calculateur se base sur un produit qui contient en plus d'un detecteur de temperature, un detecteur de CO2 et un accelerometre. Notre alarme devrait donc theoriquement durer plus longtemps.

![batterie](https://user-images.githubusercontent.com/97834284/149666301-6448f49d-da12-49de-be1a-cd0e97465412.png)


# Analyse du cycle de vie
# Comparaison

| Produit |Cout|Duree de vie batteie|Securite |Temperature|CO2|Humidite|Mouvement
|:---:|:---:|:---:|:---:|:---:|:---:|:---:|:---:|
|Notre Alarme|40€|1 an| AppKey |Oui|Non|Non|Non
|SmartVOX® | ??? |∞* | ???|Non|Non|Non|Non
|R602A LoRaWAN Wireless Siren|179 €|5 ans| Encrypt-RF™ Security|Non|Non|Non|Non
|ACS Switch Buzz®| ??? | 5 ans |???| Non|Non|Non|Oui
|MClimate|160 €| 10 ans | End-to-End encryption (AES-CTR)|Oui|Oui|Oui|Non


∞ = alimentation secteur

# Conclusion

Malgres une alarme assez minimaliste, nous avons reussi a detecter la temperature, envoyer l'information au Chirpstack qui la renvoie sur Cayenne. Le signal sonore et lumineux s'activent des le changement brusque de temperature ou l'appui du boutton. Nous avons appris les bases de l'internet des objets et avons compris le fontionnement des differents aspects permettant la mise en route d'un objet connecte, que ce soit materiel ou logiciel.
