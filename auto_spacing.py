import os, pprint

data = """
General Vocabulary / Vocabulaire général / Vocabulario general

Press “Start” to Continue			Appuyez sur "Start" pour continuer						Pulsa “Start” para continuar
File Select					Sélection de File									Selección de archivo
Hold L+R to Delete Save File		Maintenez L + R pour supprimer le file de sauvegarde			Mantén L + R para Eliminar Datos de Guardado
Score							Score												Puntuación

Chapter Names

A very good place to start			Une très bonne place pour commencer			Un buen lugar en el que comenzar
Welcome to the island				Bienvenue sur l'île 						Bienvenidos a la isla	                
The Craigslist islanders			Les insulaires de Craigslist				Los isleños de Craigslist

The Pizza guy who doesn’t make pizza and also hates pizza
Le pizzaiolo qui ne fait pas de pizza et qui déteste aussi la pizza
El chico pizzero que no cocina pizza y además detesta la pizza

Bad things happen when you wake Maple up from a nap
de mauvaises choses arrivent quand tu réveilles Maple après une sieste
Cosas terribles suceden cuando despiertas a Maple de una siesta

How are you supposed to react to something like that, like, seriously
Je ne sais pas comment les gens sont censés réagir à ça
En serio, ya me dirás cómo se supone que he de reaccionar a algo como eso


Script

4:15 AM                          January 1st, 2000                Providence of Nord Louisiane,    La République Laurentides
                                 AHHHHG.                          I've been driving for hours.     My right foot's asleep, and the  left one isn't too far behind.        
                                 Look at that gumbo.              It has to be cold by now.        I can't believe they wanted me   to bring the food.
                                 Y'know....                       If I don't see that castle in    fifteen minutes, I might just    head back.
                                 At least the drive was nice,     I guess.
                                 Okay, I give up. There's no way  that I'm gonna-
                                 .....Oh.
                                 I.. can't decide if I'm          relieved or disappointed.

                                 *knock*                          *knock*                          *knock*
                                 I wonder if they can even        hear me in there... This place   looks huge.
                                 '.....coming!'
4:15 AM                          1 de Enero, 2000                 Providence de Nord Louisiane,    La République Laurentides
                                 AHHHHG.                          Conduje durante horas. 	      Mi pie derecho está dormido y	 el otro va por el mismo camino.        
                                 Y este gumbo...                  Tiene que estar ya helado.       No puedo creer que quisieran     que les llevase la comida.
                                 A decir verdad...                Si no veo ese castillo en        quince minutos, tal vez me dé    la vuelta.
                                 Aunque el viaje fue agradable,   supongo.
                                 Está bien, me rindo. No hay      manera de-
                                 .....Oh.
                                 No sabría decir si me siento     aliviada o decepcionada.

                                 *knock*                          *knock*                          *knock*
                                 Me pregunto si podrán llegar a   escucharme... Este lugar         parece enorme.
                                 '¡...Voooy!'
04h15 					1er janvier 2000 Providence de Nord Louisiane, La République Laurentides
                                 AHHHHH. J'ai conduit pendant des heures. Mon pied droit dort et l'autre va dans le même sens.
                                 Et ce gombo... Il doit être congelé maintenant. Je n'arrive pas à croire qu'ils voulaient que je leur apporte de la nourriture.
                                 Pour dire la vérité... Si je ne vois pas ce château dans quinze minutes, je pourrais faire demi-tour.
                                 Le trajet était agréable cependant, je suppose.
                                 Bon, j'abandonne. Il n'y a pas moyen-
                                 .....Oh.
                                 Je ne peux pas dire si je suis soulagé ou déçu.

                                 *Toc Toc Toc*
                                 Je me demande s'ils peuvent même m'entendre... Cet endroit semble immense.
                                 '... Voooy!'



ENOKI                            Hey, Maple!!                     C'mon in, allez!
MAPLE                            Alright, so where do I plug this crock-pot in at? Are there any   plugs?
MAPLE                            I take it that I'm late enough   y'all probably already ate       something else.
ENOKI                            Well, we've got an outhouse,     but that's the only place with   electricity. And yeah, we got    some chicken.
ENOKI                            We missed you earlier!
MAPLE                            Well I'm finally here, now. So,  where is- Oh! Salut, Aaron.
AARON                            Bonsoir! Or Bonjour more like, I guess, it's technically morning, isn't it? I'm just glad you got  here. Happy new millenium!
MAPLE                            Happy new millenium! Y'all reallyare in the middle of nowhere, youknow that?
DEL                              Maple! You're here! Happy 2000!
MAPLE                            Delphine Thibodeaux!             My goodness it's been... what, a year? Salut!
DEL                              Hey, girl! Glad you're here -    Don't worry, we've been waiting  to break out the wine and        eclairs until you showed up.
DEL                              We're all boring adults, though, so no promises about how late we would have stayed up for you.
ENOKI                            So Maple, what have you been up  to lately? Have we even talked   since the wedding?! I missed my  best friend!
MAPLE                            Surely your husband's been       keeping you busy, I suppose.
AARON                            Well, we're obviously living in acastle now, so that's been an    adventure.
ENOKI                            I am a princess.
MAPLE                            It takes a little more than just a castle to be a princess.
ENOKI                            I'm a duchess?
MAPLE                            I- uhm...                        Hmm...                           You know what?                   It's too late for this.
MAPLE                            Anyway, I've been alright, I've  only got one semester left, then I'll be a school teacher.  Then? I don't know.
AARON                            Still trying this teacher thing, huh? Even though you've told me  a million times you'd rather be  anything but a teacher?
AARON                            Are there no degrees for people  who can shoot fire out of their  hands?
MAPLE                            ...None I want, at least.
AARON                            Well, a teacher with fire magic  sounds pretty cool to me.
ENOKI                            *yawn*                           Goodness, I'm sleepy. Hey, how   about we all go to bed and catch up in the morning?
ENOKI                            Hey Maple, you wanna have like   a sleepover? Like we can pretend we're college roommates again?
MAPLE                            I mean... Sure, I guess.
ENOKI                            Goodnight, Del!                  Hey, Aaron, see ya tomorrow?     Bright 'n early?
AARON                            Sure thing, Noke-noke.                                            *kiss*
MAPLE                            I am never going to get used to  that.
ENOKI                            Alright, grab your bag and I'll  show you where we're staying.    Allons-y!
MAPLE                            Wow.. It's sort of chilly in     here, isn't it?
ENOKI                            Well silly, why'd ya wear a tank top and shorts in the middle of  December? Can't ya just light a  fire?
MAPLE                            So, how long are you two going to stay here? You can't just stay   thirty miles from civilization   without electricity forever.
ENOKI                            We're happy, so we think a long  time.
MAPLE                            I mean, what does Aaron think of all this? The Aaron I remember   growing up would be a little more...responsible.
ENOKI                            I don't wanna sound rude but...  Aren't you guys used to growing  up in places like, er, in a car?
MAPLE                            Enoki, we all know you're rich,  no need to flaunt it.
ENOKI                            But didn't you literally grow up in a car? I mean, compared to    that, a castle is pretty nice,   right?
MAPLE                            It just seems.. rash. I don't    mean to take the fun out of it,  but I can't help but think this  was a really, really bad idea.
ENOKI                            Coming from the girl who got     embarrassed of her grades        freshman year and decided to justup and run away from college.
MAPLE                            Oh come on, that was your idea   first.
ENOKI                            Hey, I'll take it!! '97... Yeah, that was one of the best years   of my life, easy.
ENOKI                            So, after college, you got any   plans for where you wanna live?
MAPLE                            I'll figure something out.
ENOKI                            Aaron and I were chatting and,   y'know, there's a school not too far off you could teach at,      maybe you could.. y'know..
MAPLE                            Absolutely NOT. I'll make sure   to get myself a real adult       apartment.
MAPLE                            When you get tired of this place,maybe you can move in with me.
ENOKI                            The kinda things you choose to befunny about Maple, it'll never   cease to amaze me.
ENOKI                            Hey- I'm feeling down and that's stupid! You wanna go on another  Maple and Enoki adventure like   old times?! 
ENOKI                            Let's go explore the castle!!
MAPLE                            Hold up, you bought this castle  and hadn't explored it all first?
ENOKI                            Well duh, I'm taking my sweet    time with it -- it's a castle!   Allons-y, let's explore!
ENOKI                            Hé, Maple! C’mon in, allez!
MAPLE                            D'accord, où puis-je brancher cette mijoteuse? Y a-t-il des prises par ici?
MAPLE                            Je suppose que je suis trop tard et que tu as déjà mangé autre chose.
ENOKI                            Nous avons un évier extérieur, mais c'est le seul endroit avec électricité. Et oui, nous-autres avons déjà mangé du poulet.
ENOKI                            Tu nous-autres as tellement manqué!
MAPLE                            Eh bien, je suis enfin arrivé. Où est- Oh! Salut, Aaron.
AARON                            Bonsoir! Ou plutôt Bonjour, qui est techniquement déjà demain. Non? Quoi qu'il en soit, nous-autres sommes heureux de te voir. Joyeux millénaire!
MAPLE                            Joyeux millénaire! Vous autres êtes au milieu de nulle part, vous autres le savez, n'est-ce pas?
DEL                              Maple! Tu es venu! Joyeux 2000!
MAPLE                            Delphine Thibodeaux! Mon Dieu, ça fait combien de temps déjà? Un an? Bonjour!
DEL                              Hé ma fille! Quelle joie de te voir. Ne te gratte pas, on t'attend pour ouvrir le vin et sortir les éclairs.
DEL                              Bien que nous-autres soyons tous des adultes ennuyeux maintenant. Donc je ne peux pas te promettre qu'on va veiller tard.
ENOKI                            Hey Maple, comment ça va jusqu'à présent? Avons-nous même parlé depuis le mariage?! Mon meilleur ami me manque!
MAPLE                            Votre mari a certainement dû t'occuper, je suppose.
AARON                            Well, comme tu vois, nous-autres vivons dans un château maintenant, et ça a été toute une aventure.
ENOKI                            Je suis une princesse.
MAPLE                            Il faut un peu plus qu'un grand château pour être une princesse.
ENOKI                            Alors je suis duchesse?
MAPLE                            Je- euh... Hmm... You know what? Il est trop tard pour ça.
MAPLE                            Ça s'est bien passé pour moi en tout cas, je n'ai besoin que d'un semestre pour être enseignant. Donc je ne sais pas, c'est tout.
AARON                            Tu es de retour avec ça, tu veux être professeur, hein? Même si tu as dit un million de fois que tu serais tout sauf un professeur?
AARON                            N'y a-t-il pas des diplômes pour les gens qui peuvent cracher du feu avec leurs mains?
MAPLE                            Pas au moins un qui m'intéresse.
AARON                            Well, un professeur de magie du feu me semble cool.
ENOKI                            *Aaawn* mon goodness, je me suis endormi. Et si on allait se coucher maintenant et qu'on continuait à bavarder demain?
ENOKI                            Hey Maple, est-ce qu'on fait une soirée pyjama? Pouvons-nous faire semblant d'être à nouveau colocataires à l'université?
MAPLE                            C'est... D'accord, je suppose.
ENOKI                            Bonne nuit Del! Salut Aaron, est-ce que je te verrai demain matin? Très tôt?
AARON                            Bien sûr, Noc-Noc. *embrasser*
MAPLE                            Je ne m'y habituerai jamais.
ENOKI                            Très bien, attrape ta valise et je te montrerai où tu vas rester. Allons-y!
MAPLE                            Wow... Il fait trop froid ici, n'est-ce pas?
ENOKI                            Hé silly, qui penserait à porter un débardeur et un short en plein mois de décembre? Tu pourrais allumer un feu.
MAPLE                            Et combien de temps comptes-tu rester ici? Tu ne peux pas être à près de 50 km de la civilisation sans électricité pour toujours.
ENOKI                            Nous sommes heureux ici, donc je pense que nous-autres serons ici pour longtemps.
MAPLE                            Que pense Aaron de tout cela? L'Aaron dont je me souviens avoir grandi aurait été un peu plus... responsable.
ENOKI                            Je ne veux pas paraître grossier mais... N'as-tu pas l'habitude de grandir dans des endroits comme dans une voiture?
MAPLE                            Enoki, nous-autres savons déjà que tu es riche, tu n'as pas à t'en vanter.
ENOKI                            Mais tu as littéralement grandi dans une voiture, n'est-ce pas? Par rapport à cela, n'est-ce pas formidable de vivre dans un immense château?
MAPLE                            C'est juste... C'est fou. Je ne me moque pas de toi ou quoi que ce soit du genre, mais je pense vraiment que c'est une très mauvaise idée.
ENOKI                            Et cette opinion vient de la fille qui avait honte de ses notes en première année et a décidé d'abandonner l'université...
MAPLE                            Come on, c'était ton idée au départ.
ENOKI                            Hé, je vais le prendre!! '97... Ouais, c'était l'une des meilleures années de ma vie, aisé.
ENOKI                            Donc, après l'université, tu as des plans pour où tu veux vivre?
MAPLE                            Je vais trouver quelque chose.
ENOKI                            Aaron et moi discutions et, tu connais, il y a une école pas trop loin où tu pourrais enseigner, peut-être que tu pourrais... tu connais...
MAPLE                            Absolument PAS. Je ferai en sorte de me trouver un vrai appartement pour adultes.
MAPLE                            Quand tu en auras marre de cet endroit, tu pourras peut-être emménager avec moi.
ENOKI                            Le genre de choses que vous choisissez d'être drôles à propos de Maple, ça ne cessera jamais de m'étonner.
ENOKI                            Hey- Je me sens déprimé et c'est stupide! Tu veux vivre une autre aventure Maple et Enoki comme au bon vieux temps?!
ENOKI                            Allons explorer le château!!
MAPLE                            Attends, tu as acheté ce château et tu ne l'avais pas tout exploré avant ?
ENOKI                            Eh bien duh, je prends mon temps avec ça - c'est un château! Allons-y, explorons!
ENOKI                            ¡Hey, Maple!                     ¡Entra, allez!
MAPLE                            Está bien, ¿Dónde puedo enchufar esta olla de cocción lenta?      ¿Hay enchufes por aquí?
MAPLE                            Supongo que he llegado muy tarde y ya habréis comido cualquier    otra cosa.
ENOKI                            Tenemos un lavabo exterior,      pero ese es el único sitio con   electricidad. Y sí, ya hemos    comido pollo.
ENOKI                            ¡Te hemos extrañado muchísimo!
MAPLE                            Bueno, pues al fin he llegado.   ¿Dónde está- ¡Oh! Hey, Aaron.
AARON                            ¡Bonsoir! O Bonjour más bien,    que técnicamente ya es mañana.   ¿No? De todas formas nos        alegra verte. ¡Feliz milenio!
MAPLE                            ¡Feliz milenio! Estáis en mitad  de la nada, ¿lo sabéis, no? 
DEL                              ¡Maple! ¡Has venido! ¡Feliz 2000!
MAPLE                            ¡Delphine Thibodeaux!            Dios mío, ¿Cuánto tiempo ha      pasado ya? ¿Un año? ¡Salut!
DEL                              ¡Hey, chica! Qué alegría verte.  No te rayes, que te hemos estado esperando para abrir el vino     y sacar los éclairs.
DEL                              Aunque ya todos somos unos       aburridos adultos. Así que no    puedo prometerte que vayamos a   quedarnos hasta las tantas.
ENOKI                            Oye Maple, ¿cómo te ha ido       hasta ahora? ¡¿Acaso siquiera    hemos hablado desde la boda?!    ¡Extraño a mi mejor amiga!
MAPLE                            Desde luego tu marido ha tenido  que mantenerte ocupada, supongo.
AARON                            Bueno, como ves, vivimos en un   castillo ahora, y eso ha sido    toda una aventura.
ENOKI                            Soy una princesa.
MAPLE                            Hace falta un poquito más que un gran castillo para ser princesa.
ENOKI                            ¿Entonces soy una duquesa?
MAPLE                            Yo- ehm...                       Hmm...                           ¿Sabes qué?                      Es muy tarde para esto.
MAPLE                            Me ha ido bien en cualquier caso,tan sólo me faltaría un semestre para poder ser profesora.        Así que no sé, eso es todo.
AARON                            Vuelves con eso de querer ser    profesora, ¿eh? ¿Aunque dijiste  millones de veces que serías     cualquier cosa menos profe?
AARON                            ¿No existen grados para personas que puedan lanzar fuego por las  manos?
MAPLE                            No al menos uno que me interese.
AARON                            Bueno, a mi una profe con magia  de fuego me suena como algo guay.
ENOKI                            *Aaawn*                          Cielos, me caigo del sueño.      ¿Y si nos acostamos ya y seguimos mañana con la cháchara?
ENOKI                            Hey Maple, ¿hacemos una fiesta   de pijamas? ¿Podemos hacer como  que volvemos a ser compañeras de  habitación de la universidad?
MAPLE                            Esto... Está bien, supongo.
ENOKI                            ¡Buenas noches, Del!             Ey Aaron, ¿te veré por la mañana?¿Bien tempranito?
AARON                            Claro que sí, Noke-noke.                                          *beso*
MAPLE                            Nunca terminaré de acostumbrarme a eso.
ENOKI                            Muy bien, agarra tu maleta y te  mostraré donde vas a quedarte.  ¡Allons-y!

MAPLE                            Wow... Hace demasiado frío aquí, ¿no?
ENOKI                            Bobita, ¿A quién se le ocurre    llevar una camiseta sin manga   y shorts en pleno Diciembre?     Podrías encender un fuego.
MAPLE                            ¿Y cuánto tiempo pensáis quedaroslos dos aquí? No podéis estar   a casi 50km de la civilización   sin electricidad por siempre.
ENOKI                            Somos felices aquí, así que creo que nos quedaremos mucho tiempo.    
MAPLE                            ¿Qué piensa Aaron de todo esto?  El Aaron que recuerdo ver crecerhabría sido un poco más...       responsable.
ENOKI                            No quiero sonar grosera pero...  ¿Ustedes no estáis acostumbradosacrecer en sitios como en       un coche?
MAPLE                            Enoki, ya sabemos que eres rica, no tienes por qué fardar de ello.
ENOKI                            Pero si literalmente tú creciste en un coche, ¿no? Comparado con  eso, ¿no es genial vivir en un   enorme castillo?
MAPLE                            Es sólo que... Es una locura. No me río de ti ni nada por el      estilo, pero realmente creo que  esto es una terrible idea.
ENOKI                            Y esa opinión viene de la chica  que se avergonzó de sus notas    del primer año y decidió dejar   la universidad...
MAPLE                            Venga ya, para empezar esa       fue idea tuya.
ENOKI                            ¡Eh, Oye! Pero sí, eso fue en    el 97... Lo recuerdo como uno de los mejores años de mi vida.
ENOKI                            ¿Has pensado dónde te gustaría   vivir cuando termines tus        estudios?
MAPLE                            Ya se me ocurrirá algo.
ENOKI                            Aaron y yo estuvimos hablando,   y resulta que hay una escuela queno queda demasiado lejos, quizá  podrías... Bueno, ya sabes.
MAPLE                            NI de co[a. Me aseguraré de      conseguir un apartamento digno deun adulto hecho y derecho.
MAPLE                            Cuando te aburras de este sitio, quizá deje que te mudes conmigo.
ENOKI                            Maple, las cosas que eliges      decir para hacerte la graciosa   nunca dejarán de sorprenderme.
ENOKI                            Oye- Creo que me está dando una  bajona y eso es estúpido. ¿Y si  nos vamos de aventuras como en    los viejos tiempos?
ENOKI                            ¡¡Vamos a explorar el castillo!!
MAPLE                            Para el carro, ¿de veras         compraste el castillo y aún no   lo has explorado?
ENOKI                            Bueno, digamos que estoy         tomándome mi tiempo con él...    ¡Es un gran castillo después de    todo, Allons-y!




ENOKI                            I wanna explore the big          bookshelf room first!
MAPLE                            Sure, whatever.
ENOKI                            I think you're gonna see why     when we get there.
ENOKI                            If you want me to lead,          just press 'B'.
MAPLE                            ...Huh?
ENOKI                            What?
...
AARON                            Bonjour! Did you sleep well?
MAPLE                            Yeah, it was ok I guess.
ENOKI                            Bonjour! So.. We found something cool while you were sleeping, but you've gotta promise you won't be mad.
MAPLE                            You know I can't promise that.
ENOKI                            Remember that book you wanted me to get? Well, it's a world atlas!And we spotted something really  fun!
ENOKI                            So, we found this island up in   Lake Supérieur called Tremblay  Island!
MAPLE                            Aw, that's fun. I was afraid that there'd be some kind of.. catch.
ENOKI                            Well, we, uh- figured it'd be fun if, well, the idea came from Del,so...
DEL                              Last time we talked, my cousin   Rufus was obsessed with starting his own tiny country.
AARON                            There's work not too far out, so if we need to pick up supplies,  it shouldn't be very difficult.
ENOKI                            With the money we could make     selling off the castle, and with your magic, we were thinking-
MAPLE                            WHOA WHOA WHOA,                  JUST HOLD UP FOR A MINUTE.
MAPLE                            Are you seriously telling me that you're going to SELL this castle and move to this random island,
MAPLE                            All because it shares the same   last name as us?
ENOKI                            As a bonus, we're thinking we're gonna secede from the Laurentidesand be our own country, too.
MAPLE                            ...I...
MAPLE                            ...
MAPLE                            ...I'm going to need some time to process this.
AARON                            It sounds insane, but we've gone over the details, and it seems   like this could actually happen.
ENOKI                            I know we had that talk last     night, but..
MAPLE                            And then what's next?            What happens after you get bored of being your own little island?
MAPLE                            Do you want to be the Pope? The  Queen of France? Are you going to want your own planet?
MAPLE                            And for what it's worth you're   lucky enough that you'll probably get it. But you know what?
MAPLE                            I'm going to settle in reality   with my *real* job and stay out  of starving to death on some     rock,
MAPLE                            Or worse, getting locked up in   federal prison for breaking some sort of weird law.
MAPLE                            Look.... It's been fun, but I    need to go home. I'm done with   this.
MAPLE                            Aaron, Enoki, Delphine, it's been fun, but.... I need some time.
AARON                            Are you sure? We can change the  subject, we were just talking.   We've got breakfast made if you  want some.
MAPLE                            ..Alright, I'll stay a little    longer, but I do need to be      heading out soon.

                                 Hmm, hmm hmm hmm....
                                 For goodness' sake, when is that pizza going to show up? Wasn't it supposed to be here in under     twenty minutes?
                                 Have I checked my mail today? I  probably should go ahead and     check.
                                 Huh, what's this? From the       Tremblay household? I guess I    haven't heard from Aaron and     Enoki in a while.
                                 Can't wait to read about how much they want to move in with me now.

                                             Hey, Maple!
                                 Hold on, got this backwards.

                                             'Hey, Maple!'
                                       'We thought we'd send            you a quick letter to            give you an update.'
                                       'We sold the castle and          got to make enough to            buy a nice trailer home.'
                                       'However, that's not all-        we got it set up on our          new island!!'
                                 I'm...                           That's it,                       I'm gonna kill 'em.
                                       'So, we've decided that          we're going to name it-..'

MAPLE                            Thunder my DOG,                  I have had ENOUGH,               they are ALL gonna get it!
MAPLE                            That's it! I'm at my limit.      They're going to DIE ALONE and   it's gonna be ALL their fault.
MAPLE                            When they're tired of living this island fantasy, they're gonna    come here, and you know what I'll say?
PIZZA GUY                        What will you say?
MAPLE                            I'll say NO!
PIZZA GUY                        I dunno, living on an island by  yourself sounds kinda nice.
MAPLE                            It's the nicest thing on the     planet, but they're gonna ruin itcos they're the most incompetant people on the planet!
PIZZA GUY                        If I were you, I'd go up and     teach 'em how to run the island.
MAPLE                            I guess I'm gonna have to huh?   They're gonna die up there or    freeze to death!
MAPLE                            But I can't. I've gotta be the   better person and stay in adult  world.
PIZZA GUY                        Right, it's more important to    keep buying pizza and crying     yourself to sleep on your couch  like ya' do every night?
MAPLE                            Is it really that obvious?
PIZZA GUY                        Yeah, we all take turns at the   place to see who'll get to       deliver to the 'sad pizza girl'.
MAPLE                            Spectacular.
MAPLE                            Well, I suppose....              I mean, I don't exactly have the money to pay rent this month cos of all the pizza...
PIZZA GUY                        So... we gonna tip for today's   counseling session?

ENOKI                            ¡Primero me gustaría ver la      biblioteca de la gran estantería!
MAPLE                            Claro, vamos.
ENOKI                            Creo que entenderás por qué      quiero ir para allá en cuanto    lo veas!
ENOKI                            Si prefieres que vaya delante,   sólo tienes que pulsar 'B'.
MAPLE                            ... ¿Cómo?
ENOKI                            ¿Qué?
...
AARON                            ¡Bonjour! ¿Habéis dormido bien?
MAPLE                            Sí, he dormido bien, creo.
ENOKI                            ¡Bonjour! Oye... Hemos encontradoalgo chulísimo mientras dormías, pero tienes que prometerme       que no te enfadarás!
MAPLE                            Sabes muy bien que no puedo      prometerte eso.
ENOKI                            ¿Recuerdas el libro que querías  que tomara? Pues bien, es un     Atlas del mundo, ¡y nos dimos    cuenta de algo  divertido!
ENOKI                            ¡Hemos visto esta isla del       Lago Supérieur llamada Tremblay  Island!
MAPLE                            Aw, qué gracioso. Pensaba que    ibas a decir algún juego de      palabras o algo por el estilo.
ENOKI                            Bueno, nosotros, eh- hemos       pensado que sería divertido si,  bueno, Del ha tenido la idea,     así que...
DEL                              La última vez que hablamos,      mi primo Rufus estaba obsesionadocon comenzar su pequeño país.
AARON                            Podemos trabajar cerca de ahí,   y no debería sernos muy difícil  conseguir los suministros que     nos hagan falta.
ENOKI                            Con el dinero que consigamos     vendiendo el castillo y gracias  a tu magia, hemos pensado que-
MAPLE                            WHOA WHOA WHOA,                  ESPEREN UN MOMENTO.
MAPLE                            ¿De veras me estáis diciendo que vais a VENDER este castillo para mudaros a esta isla-
MAPLE                            por el simple motivo de que      compartamos el mismo apellido     con ella?
ENOKI                            Y además, estamos pensando en    separarnos de Laurentides para    fundar nuestro propio país.
MAPLE                            ...Yo...
MAPLE                            ...
MAPLE                            ... Creo que voy a necesitar un  tiempo para procesar todo esto.
AARON                            Puede que parezca una locura,    pero hemos estado informándonos   y parece posible que podamos    lograrlo.
ENOKI                            Sé que tuvimos aquella charla    anoche, pero...
MAPLE                            ¿Y ahora qué?                    ¿Qué pensáis hacer cuando os      aburráis de vuestra isla?
MAPLE                            ¿Quieres ser la Papisa? ¿Quizá   la Reina de Francia? ¿Querrás     tener tu propio planeta?
MAPLE                            Y probablemente tendrás la       suficiente suerte como para       conseguir lo que quieras. Pero, ¿sabes qué?
MAPLE                            Yo estaré con los pies en la     tierra con un trabajo *de verdad* y evitaré morirme de hambre     aunque sea arrastrándome.
MAPLE                            O peor aún, viviré dignamente    aunque por ello pueda terminar en prisión por haber violado       algún tipo de ley extraña.
MAPLE                            Mira.... Ha sido muy divertido,  pero necesito volver ya a casa.  Estoy harta de todo esto.
MAPLE                            Aaron, Enoki, Delphine, me hace  feliz haberos visto de nuevo,    pero necesito tomarme un tiempo.
AARON                            ¿Estás segura? Podemos hablar de cualquier otra cosa si quieres.  Podrías unirte y desayunar con   nosotros.
MAPLE                            ...Bien, me quedaré un poco más, pero debería irme pronto.

                                 Hmm, hmm hmm hmm....
                                 ¿Cuándo diablos va a llegar esa  pizza? ¿No se suponía que tenía  que llegar hace 20 minutos?
                                 ¿He mirado hoy el correo? Quizá  no sería mala idea ir a echar    un vistazo.
                                 Huh, ¿qué es esto? ¿De la casa   Tremblay? Hace mucho que no sé   nada de Aaron y Enoki.
                                 No puedo esperar a leer lo       mucho que desean venir a vivir   conmigo.

                                            ¡Hey, Maple!
                                 Espera, lo puse al revés.

                                            '¡Hey, Maple!'
                                       'Pensamos en enviarte            una carta para                   tenerte informada'
                                       'Hemos vendido el                castillo y hemos                 comprado una casa rodante.'
                                       'Aunque eso no es todo-          ¡Ya la hemos instalado           en nuestra nueva isla!'
                                 Ya me...                             Me tienen hasta la coronilla.    Juro que me los cargo.
                                       'Así que hemos decidido          que la vamos a llamar-..'

MAPLE                            Que baje Dios y me pare,         Ya tuve SUFICIENTE,              ¡Estos se van A ENTERAR!
MAPLE                            ¡Ya han conseguido ponerme brava!Todos ellos van a MORIRSE SOLOS. Se buscaron su propia perdición.
MAPLE                            Cuando se dejen de tanta fantasía con eso de la isla van a venir   aquí, ¿y sabes qué les diré?
PIZZA GUY                        ¿Qué les vas a decir?
MAPLE                            ¡Les diré que NI de co[a!
PIZZA GUY                        No sé, eso de vivir en una isla  por ellos mismos suena genial.
MAPLE                            No se me ocurre nada mejor en    el mundo, pero les va a ir fatal.¡Porque todos ellos son unos     auténticos incompetentes!
PIZZA GUY                        Si yo fuera tú, me apuntaría     y les enseñaría cómo llevar la   isla adelante.
MAPLE                            ¿Supongo que tampoco me queda    otra? ¡Van a palmarla de         cualquier forma o incluso        podrían morir de frío!
MAPLE                            Pero no puedo dejar mi vida de   lado. Debo ser coherente conmigo misma y hacerme hueco en la      sociedad.
PIZZA GUY                        Claro, ¿es más importante seguir comprando pizza y llorar hasta   quedarte frita como haces todas  las noches?
MAPLE                            ¿Tan evidente es?
PIZZA GUY                        Sí, nos vamos turnando para ver  a quién toca llevarle la comida  a la depresiva chica consumidora de pizzas.
MAPLE                            Increíble.
MAPLE                            Aunque supongo que es así...     La verdad es que después de pedir tantapizza apenas me llega para pagar la renta del mes.
PIZZA GUY                        Bueno... ¿Dónde está mi propina  después la sesión de hoy?
ENOKI                            J'aimerais d'abord voir la bibliothèque sur la grande étagère!
MAPLE                            Bien sûr, allez.
ENOKI                            Je pense que tu connais pourquoi je veux y aller dès que tu le verras!
ENOKI                            Si tu préférez qu'il mène, appuyez simplement sur 'B'.
MAPLE                            ...Uh, what?
ENOKI                            Quoi?
...
AARON                            Bonjour! Aves tu bien dormi?
MAPLE                            Oui, j'ai bien dormi, je pense.
ENOKI                            Bonjour! Hey... Nous avons trouvé quelque chose de vraiment cool pendant que tu dormais, mais tu dois me promettre que tu ne vas pas te fâcher!
MAPLE                            Tu sais très bien que je ne peux pas te le promettre.
ENOKI                            Tu souviens-tu du livre que tu voulais que je prenne? Well, c'est un Atlas du monde, et nous-autres avons réalisé quelque chose de drôle!
ENOKI                            Nous avons vu cette île du lac Supérieur appelée Tremblay Island!
MAPLE                            Aww, c'est marrant. Je pensais que tu allais dire un jeu de mots ou quelque chose comme ça.
ENOKI                            Well, nous, euh- nous-autres pensions que ce serait amusant si, eh bien, Del avait l'idée, alors...
DEL                              La dernière fois que nous avons parlé, mon cousin Rufus était obsédé par la création de son petit pays.
AARON                            Nous pouvons travailler à proximité, et il ne devrait pas être trop difficile d'obtenir les fournitures dont nous avons besoin.
ENOKI                            Avec l'argent que nous recevons de la vente du château et grâce à votre magie, nous avons pensé que-
MAPLE                            WHOA WHOA WHOA, ATTENDEZ UNE MINUTE.
MAPLE                            Êtes-tu vraiment en train de me dire que tu allez VENDRE ce château pour déménager sur cette île-
MAPLE                            pour la simple raison que nous-autres partageons le même nom de famille avec elle?
ENOKI                            Et d'ailleurs, nous songeons à nous détacher des Laurentides pour fonder notre propre pays.
MAPLE                           ... je...
MAPLE                           ...
MAPLE                           ... Je pense que je vais avoir besoin de temps pour assimiler tout ça.
AARON                            Cela peut sembler fou, mais nous avons fait nos recherches et il semble que nous pourrions réussir.
ENOKI                            Je sais qu'on a eu cette conversation hier soir, mais...
MAPLE                            Et maintenant? Que comptes-tu faire lorsque tu... tu ennuyez sur votre île?
MAPLE                            Tu veux être la grande prêtresse? Peut-être la reine de France? Tu veux avoir ta propre planète?
MAPLE                            Et tu auras probablement la chance d'obtenir ce que tu veux. Mais, tu connais what?
MAPLE                            Je vais garder les pieds sur terre avec un *vrai* travail et éviter de mourir de faim en me traînant.
MAPLE                            Ou pire encore, je vivrai dignement même si je risque de finir en prison pour avoir enfreint une loi étrange.
MAPLE                            Ecoutez... Ça a été très amusant, mais je dois rentrer à la maison maintenant. Je suis fatigué pour tout ça.
MAPLE                            Aaron, Enoki, Delphine, je suis content de te revoir, mais j'ai besoin de prendre du temps.
AARON                            Tu es sûr? On peut parler d'autre chose si tu veux. Tu peux aussi prendre le petit déjeuner avec nous-autres si tu veux.
MAPLE                            ...Well, je resterai un peu plus longtemps, mais je devrais bientôt partir.

                                 Hum, hum hum hum....
                                 Quand diable cette pizza arrive-t-elle? N'était-il pas censé arriver il y a 20 minutes?
                                 Ai-je vérifié le courrier aujourd'hui? Ce ne serait peut-être pas une mauvaise idée d'aller y jeter un œil.
                                 Hein, qu'est-ce que c'est? De la maison Tremblay? Je n'ai pas eu de nouvelles d'Aaron et d'Enoki depuis longtemps.
                                 J'ai hâte de lire à quel point ils veulent venir vivre avec moi.

Hé, Maple!
                                 Attends, je l'ai mis à l'envers.

                                 'Hé, Maple!'
                                 "Nous avons pensé à t'envoyer une lettre pour te tenir informé"
                                 "Nous avons vendu le château et acheté un mobil-home.
                                 "Ce n'est pas tout, nous l'avons déjà installé sur notre nouvelle île!"
                                 Je suis déjŕ... Ils m'ont hissé ŕ la couronne. Je jure que je vais les prendre.
                                 'Alors nous avons décidé de l'appeler-..'

MAPLE                            Oh my gosh, j'en ai eu ASSEZ, Ceux-ci vont le découvrir!
MAPLE                            Ils m'ont déjà mis en colère, ils vont tous MOURIR SEUL. Ils ont apporté leur propre chute.
MAPLE                            Quand ils arrêteront tant de fantasmes sur l'île, ils vont venir ici, et tu sais ce que je vais leur dire?
PIZZA GUY                        Qu'est-ce que tu vas leur dire?
MAPLE                            Je leur dirai ABSOLUMENT PAS!
PIZZA GUY                        Mô ne sais pas, vivre sur une île par eux-mêmes sonne bien.
MAPLE                            Je ne vois rien de mieux au monde, mais ça va être terrible pour eux, parce qu'ils sont tous complètement incompétents!
PIZZA GUY                        Si j'étais tu, moi m'inscrirais et leur montrerais comment gérer l'île.
MAPLE                            Je suppose que je n'en ai pas d'autre? Ils vont la battre de toute façon ou ils pourraient même mourir de froid!
MAPLE                            Mais je ne peux pas mettre ma vie de côté. Je dois être cohérent avec moi-même et me faire une place dans la société.
PIZZA GUY                        Bien sûr, est-il plus important de continuer à acheter de la pizza et de pleurer à mort comme tu le fais tous les soirs?
MAPLE                            Est-ce si évident?
PIZZA GUY                        Oui, nous-autres relayons pour voir à qui revient le tour d'apporter de la nourriture à la mangeuse de pizza déprimée.
MAPLE                            Incroyable.
MAPLE                            Bien que je suppose que c'est comme ça... La vérité est qu'après avoir commandé tant de pizzas, j'ai à peine de quoi payer le mois de loyer.
PIZZA GUY                        Well... où est mon conseil après la séance d'aujourd'hui?




6:40 PM                          March 20th, 2000                 The middle of Lake Supérieur,   La République Laurentides(?)
                                 So.. That's the island.          It's cute.
                                 I'm not sure if it's sell-every- thing-I-own cute, but...
                                 J'suppose the thought of living  on an island and having no debt  is pretty cool.        
MAPLE                            How much was the ferry again?    10 dollars?
OLD SAILOR                       Aye lass, but aye've got one     warnin' fer ye befer ye dock.
MAPLE                            Oh dear, what?
OLD SAILOR                       Keep yer wits about 'ye, ye neverknow who might go to stab ye.
MAPLE                            Will you take a 20?
OLD SAILOR                       Aye, I can cut a 20.
6:40 PM                          20 de Marzo, 2000                En medio del Lake Supérieur,     La République Laurentides(?)
                                 Así que... Esa es la isla...     En realidad tiene su encanto.
                                 Aunque no sé si es lo bastante   encantadora como para vender     todas mis pertenencias.
                                 J'suppose que vivir en una isla  sin tener que pensar en cómo voy a pagar deudas valdrá la pena.
MAPLE                            ¿Cuánto costaba el viaje en el   ferry? ¿10 dólares?
OLD SAILOR                       Eso e’ chiquilla, pero viá tené  q’desirte una cosa ante’de bajá’.
MAPLE                            Madre mía, ¿ha ocurrido algo?
OLD SAILOR                       ‘Tate atenta por ahí que nunca se sabe quién podría darte una     puñalá cuando meno’ te lo espere’
MAPLE                            ¿... Aceptas 20 pavos?
OLD SAILOR                       Lo’ 20 pavo’ lo’ asepto encantao’
18h40                            20 mars 2000 Au milieu du Lac Supérieur, La République Laurentides(?)
                                 Alors... C'est l'île... Elle a vraiment son charme.
                                 Même si je ne sais pas si elle est assez charmante pour vendre toutes mes affaires.
                                 J'imagine que vivre sur une île sans avoir à penser à la façon dont je vais rembourser mes dettes en vaudra la peine.
MAPLE                            Combien a coûté le trajet en traversier? 10 dollars?
LE VIEUX MARIN                   C'est une petite fille, mais je dois te dire quelque chose avant que tu descendes.
MAPLE                            Hold up, il s'est passé quelque chose?
VIEUX MARIN                      ‘Fais attention là-bas, on ne sait jamais qui pourrait te poignarder quand tu t’y attends le moins’
MAPLE                            ...prendre 20 dollars?
VIEUX MARIN                      Je serais ravi.



ENOKI                            Maple!! You came!
MAPLE                            Yeah, this was my best option.
AARON                            How was the trip? Did it take youlong?
MAPLE                            I took the train. It was like..  three days? It was fine. I read alot. My legs hurt.
AARON                            If you'd had let us know you werecoming sooner, you know we would have arranged for a plane trip!
MAPLE                            Doesn't matter. I'm already here.So, you go from castle to mobile home? Classy.
ENOKI                            Dude, we moved outta the castle  in a 'normal home' and now you   want us to go back?
MAPLE                            No, I mean.. I guess I don't     know what I mean.
AARON                            Well, we've only got a couch, butit's very comfortable. Feel free to make yourself at home.
AARON                            We've been working hard. I've    been chopping wood for the winterand Enoki's been-
ENOKI                            So, I, uh, I thought bringing    some bunnies here would make the island a little more alive,      y'know?
ENOKI                            Turns out they started           multiplying so I spenda lotta    time tryna' keep em out of the   garden.
AARON                            How do you feel about going into the caves a little north of here?
AARON                            We've heard there's some gems in there that could be really       useful in earning us some money.
MAPLE                            I guess that isn't too difficult.
MAPLE                            Hey... thanks for the room.
AARON                            No problem.
ENOKI                            Oh, and if you haven't met Scout yet, he's pretty cool! He's down in the bunker thing outside.

ENOKI                            Well.. First day is done! I thinktoday was a lot of fun.
MAPLE                            You know what? I think I agree.  This is the most interesting day I've had in a while.
AARON                            Ready to change your mind about  this having been a bad idea?
MAPLE                            I've only been here a day, I'll  give it some time before I make  my final judgment.
AARON                            Well, we're happy to have you.   I'm sorry, we only have a couch, but I'm working on a new home.
MAPLE                            Oh, I slept on my couch back at  my old apartment all the time.   No need to worry.
ENOKI                            Aw, you slept on a couch?
MAPLE                            It was a really nice couch.
AARON                            Anyway, we're gonna get some     sleep. I've been chopping wood   all day and I'm tired.
AARON                            See you tomorrow?
ENOKI                            I'm sure I'll find more stuff to do!
MAPLE                            Thanks again. I'll do my best to not be a butt about all this.    Goodnight, y'all.
ENOKI                            Bonne nuit!

                                 Ugh.. My head.                   Why can't I sleep?
                                 Aren't you supposed to be able tosleep easier after a long day of travel and manual labor?
                                 And where's that light coming    from outside? Probably Scout or  something.
                                 Maybe I should go on a walk and  check it out.
                                 What the-                        is that a Mons d'Plonj? Is he    writing something?
                                 I guess I should go check it out.Before something bad happens.
                                 Hmmm, hmmm... hmmm....
MAPLE                            HEY! IDENTIFY YOURSELF, OR I'LL  BURN YOUR FACE OFF!
RUFUS                            AHHHH?!
                                 AH, UH.. UH, RUFUS!              RUFUS THIBODEAUX!
                                 DON'T BURN MY FACE OFF, I NEED   THAT!

MAPLE                            Oh, so you're /that/ Rufus? Del'scousin, right? I'm Maple.
RUFUS                            Oh, you're the fire elf, right?  Wish I knew that earlier when I  was trying to get this fire      started.
MAPLE                            What are you doing here?
RUFUS                            Just checking things out. I've   got my eye on the Bill & Jim     Islands next door.
RUFUS                            I really like the idea of just   having my own place and not      having to talk to anyone.
RUFUS                            I'm just worried this whole      'private island' thing is...     kind of foolhardy.
RUFUS                            Everyone this close to Quebec    speaks with that annoying accent,too.
MAPLE                            That's what I was afraid of, too.Enoki is great, but that accent  wears on me sometimes.
MAPLE                            I'm starting to hear a little    Quebec in Aaron's voice, too.    It bothers me.
MAPLE                            So what are you writing?
RUFUS                            ...                              You're going to think it's       dumb. It's a drawing.
MAPLE                            Look, I just sold everything I   owned to move to this stupid     island, your drawing isn't dumb.  
RUFUS                            ...Okay, it's a frog. I saw this picture of a frog when I was a   kid, and I don't know why, but itmakes me nostalgic.
RUFUS                            I can't quite remember what it   looked like though, so I keep    trying. I don't know why but it'ssomething I just have to do.  
MAPLE                            Yeah, that is pretty dumb, but   I think I get what you mean.
MAPLE                            Hey, I know it's not my place to offer, but you got a place to    sleep? I know it's cold out, but we have a bathtub.
RUFUS                            Oh it's fine, I'll be gone in themorning, I don't really want to  short interact with anyone else. You   seem reasonable, though.
MAPLE                            You too. It was kind of nice to  find someone with any sense to   chat for a little while.

MAPLE                            You take care of yourself,       alright? Ravi de vous rencontrer,Rufus.
RUFUS                            You too! Ravi de vous rencontrer,Maple.

                                 Hey, y'all! Scout here.                                           It's that time again!

                                 It's exciting to finally have a  real audience, ladies and        gentlemen. Er.. gentleman.
                                 It's April 1st, and you know     what that means!
                                 We've had Maple Tremblay come    move into the island for a whole day, now! Time flies, man.
                                 That's a, uh, joke..             Cuz it's April 1st, she's been   here a month now..
                                 I'll just, uh, move on.. So..    ..Right! So I finally found out  my computer password!            That's good.
                                 Oh, right- Right, the most       important bit. We have three new people moving into the village!
                                 I'm not sure we'll be able to    find any new potential islanders from Craigslist, though.
                                 They're named Diana, Eleanor, andOlivier, and they're moving into the new cabin to the northwest.
                                 Olivier has a greenhose up north,and Diana is actually an aspiringsailor! She'll be taking over    boat piloting.
                                 So just make sure to give them a warm welcome.

                                 Alright, that's all..            I suppose I'll see y'all later   today. Thanks for tuning in!

ENOKI                            Mmmmmm....                       I made popcorn, but I don't wannaget up to get it out of the      microwave.
SF: Hey Maple
ENOKI                            Could you get it, Maple?         S'il te plait?
MAPLE                            Ugh, get a room already, you two.
AARON                            Maple, this is our house.
MAPLE                            Whatever.
ENOKI                            ¡Maple, has venido!
MAPLE                            Pues sí, supongo que venir era   la mejor opción.
AARON                            ¿Qué tal el viaje? ¿Te tomó      mucho tiempo?
MAPLE                            He venido en tren. ¿Tardé unos...Tres días? No estuvo mal, tuve tiempo para leer pero me           duelen las piernas.
AARON                            ¡Si nos hubieses avisado de que  venías te habríamos pagado el    viaje en avión!
MAPLE                            Qué más da. Ya estoy aquí.       ¿Así que habéis pasado de un     castillo a una casa rodante?     Bah, lo de antes molaba más.
ENOKI                            Tía, ¿nos hemos mudado de un     castillo a una casa normal y     ahora quieres que volvamos o qué?
MAPLE                            No, sólo digo que... No sé ni    lo que estoy diciendo.
AARON                            Bueno, ahora mismo sólo tenemos  un sofá, pero es comodísimo.     Puedes sentirte como en casa y   descansar un rato.
AARON                            Hemos estado trabajando muy duro.Corté un montón de leña para     calentarnos en inviernoy Enoki-
ENOKI                            Pensé en traer unos cuantos      conejitos para que la isla se    sienta mucho más viva. ¿Sabes?
ENOKI                            Aunque resulta que comenzaron a  multiplicarse demasiado y ahora  los tengo que mantener alejados  del jardín.
AARON                            ¿Qué te parecería visitar las    cuevas que están un poco más al  norte de aquí?
AARON                            He oído que podrían contener     algunas gemas que nos ayudarían  a conseguir algo de pasta.
MAPLE                            Eso no suena demasiado difícil.
MAPLE                            Hey... y gracias por la          habitación.
AARON                            No hay de qué.
ENOKI                            Oh, y si aún no has conocido a   Scout, ¡es un tipo genial! Lo    encontrarás metido en el búnker  que hay fuera.

ENOKI                            Bueno... ¡Primer día terminado!  Creo que ha sido un día muy      divertido.
MAPLE                            ¿Sabes qué? Estoy de acuerdo.    Este ha sido el día más          interesante que he tenido en     mucho tiempo.
AARON                            ¿Vas a cambiar de opinión        respecto a aquello que decías    de que todo esto era una idea    terrible?
MAPLE                            He estado un sólo día por aquí,  dame algo más de tiempo hasta quesaque mis conclusiones finales.
AARON                            Es una pena que solo tengamos un sofá. Aunque nos alegra mucho quete quedes con nosotros hasta que construya la nueva casa.     
MAPLE                            Dormía en el sofá cuando vivía   en mi viejo apartamento, así que tampoco es que me suponga ningún problema
ENOKI                            Aw, ¿dormías en el sofá?
MAPLE                            Era un sofá maravilloso.
AARON                            En cualquier caso deberíamos     tomarnos un descanso. Estoy      reventado de cortar madera todo  el día.
AARON                            ¿Nos vemos mañana?
ENOKI                            ¡Seguro que encontramos más      cosas que podamos hacer!
MAPLE                            Muchas gracias por todo. Trataré de aportar mi granito de arena   sin ser un grano en el culo todo el rato. ¡Buenas noches!
ENOKI                            ¡Bonne nuit!

                                 Ugh... Mi cabeza...              ¿Por qué no puedo pegar ojo?
                                 ¿No debería ser capaz de dormir  después del viaje y un largo día de arduo trabajo?
                                 ¿Y de dónde viene esa luz de     fuera? Puede que sea Scout...
                                 Quizá debería salir a echar      un vistazo y ver lo que es.
                                 ¿Pero qué-?                      ¿Es eso un Mons d'Plonj? ¿Está   escribiendo algo?
                                 Debería ir a mirar antes de que  algo malo pueda suceder.
                                 Hmmm, hmmm... hmmm....
MAPLE                            ¡HEY! ¡IDENTIFÍCATE O HAGO UNA   BARBACOA CON TU CARA!
RUFUS                            ¡¿AHHHH?!
                                 ¡AH, UH.. UH, RUFUS!             ¡RUFUS THIBODEAUX!
                                 ¡ME HACE FALTA LA CARA, NO ME LA QUEMES POR FAVOR!

MAPLE                            Ah, ¿así que eres /ése/ Rufus?   El primo de Del, ¿cierto?        Encantada, soy Maple.
RUFUS                            Oh, ¿acaso eres una elfa de      fuego? Ojalá lo hubiese sabido   antes de intentar encender este  fuego.
MAPLE                            ¿Qué estás haciendo aquí?
RUFUS                            Estoy haciendo reconocimiento.   Tengo el ojo puesto en           las islas Bill & Jim de al lado.
RUFUS                            Me agrada la idea de tener un    lugar que sea únicamente para mí mismo, sin tener que tratar con  nadie.
RUFUS                            Aunque también me preocupa lo    temerario que es todo esto de    tener una 'isla privada' 
RUFUS                            Además todos los que viven cerca de Québec hablan con ese acento  tan molesto...
MAPLE                            Eso es algo también me           preocupaba. Enoki es una buena   chica, pero a veces ese acento   consigue sacarme de quicio.
MAPLE                            Empiezo a sentir cómo el acento  de Québec se apodera de la voz   de Aaron también. Qué molestia.
MAPLE                            Por cierto, ¿qué escribes?
RUFUS                            ...                              Vas a pensar que es una tontería pero estoy haciendo un dibujo.
MAPLE                            Mira, después de haber vendido   todas mis pertenencias para venira esta isla te aseguro que tu    dibujo no es una tontería.  
RUFUS                            ... Vale, es una rana. Vi esta   imagen cuando era un crío, y me  hace sentir nostálgico por algún motivo.
RUFUS                            Aunque no puedo recordar cómo    lucía realmente, así que sigo    intentándolo. No sé por qué, perosiento que debo hacerlo.
MAPLE                            Sí, ahora que lo explicas, sí    que suena como algo un poco tonto¡Pero ánimo con ello!
MAPLE                            Por cierto... ¿Tienes un lugar   en el que dormir? No puedo       ofrecerte mucho, pero hace frío  ahí fuera y tenemos ducha.   
RUFUS                            Lo agradezco, pero me iré mañana por la mañana. Y definitivamente no me apetece hablar con nadie,  aunque tú me caíste bien.
MAPLE                            Ha sido un placer encontrar a    alguien coherente con quién teneruna agradable charla.

MAPLE                            Cuídate mucho, ¿está bien?       Ravi de vous rencontrer,Rufus.
RUFUS                            ¡Tú también! Ravi de vous        rencontrer,Maple.

                                 ¡Hola a todos, llegó el momento!                                  ¡Soy Scout y aquí estoy de nuevo!

                                 Es emocionante tener por fin una audiencia de verdad, señoras y   caballeros. Ehm... Caballero.
                                 Hoy es 1 de Abril, ¡Y ya saben   lo que eso significa!
                                 Maple se ha mudado a la isla y   la hemos tenido aquí por un día  entero. ¡Cómo vuela el tiempo!
                                 Eso ha sido una, ehm, broma...   Porque ya es 1 de Abril, y lleva con nosotros todo un mes entero.
                                 M-mejor paso a otra cosa...      ¡Bien! ¡Al fin pude recuperar la contraseña de mi computadora...!
                                 Oh, cierto, cierto, otro dato.   ¡Tres nuevas personas se mudarán a la isla!
                                 Aunque no estoy seguro de que    podamos encontrar nuevos isleños potenciales de Craigslist.
                                 Sus nombres son Diana, Eleanor,  y Olivier. Y están mudándose a   la nueva cabaña situada al       noroeste.
                                 Olivier tiene una casa verde en  el norte, y Diana es una capaz   marinera aspirante. Se ocupará   de conducir el barco.
                                 ¡Así que démosles una calurosa   bienvenida!

                                 Muy bien, ya está...             Supongo que os veré a todos más  tarde. ¡Muchas gracias por       estar ahí!

ENOKI                            Mmmmmm....                       He hecho palomitas, pero no me   apetece levantarme para ir       al microondas.
SF: Hey Maple
ENOKI                            ¿Puedes ir a por ellas, Maple?   ¿S'il te plait?
MAPLE                            Ugh, agradecería dejar de ser unasujetavelas cuando estoy con     ustedes dos.
AARON                            Maple, esta es nuestra casa.
MAPLE                            Lo que tú digas.        
ENOKI                            Maple, tu es venu!
MAPLE                            Well oui, je suppose que venir était la meilleure option.
AARON                            Comment s'est passé le voyage? Cela t'a pris longtemps?
MAPLE                            Je suis venu en train. Cela m'a-t-il pris environ... Trois jours? Ce n'était pas mal, j'ai eu le temps de lire mais j'avais mal aux jambes.
AARON                            Si tu nous-autres avais dit que tu venais, nous-autres aurions payé votre trajet en avion!
MAPLE                            Qui s'en soucie. Je suis là. Alors, tu es passé d'un château à un mobil-home? Bah, ce qui était cool avant.
ENOKI                            Auntie, nous-autres avons déménagé d'un château à une maison normale et maintenant tu veux qu'on y retourne ou quoi?
MAPLE                            Non, je dis juste que... Je ne sais même pas ce que je dis.
AARON                            Well, nous-autres n'avons qu'un seul canapé pour le moment, mais il est super confortable. Tu peux te sentir chez toi et te reposer un moment.
AARON                            Nous avons travaillé très dur. J'ai coupé beaucoup de bois de chauffage pour nous-autres garder au chaud en hiver, et Enoki-
ENOKI                            J'ai pensé apporter quelques lapins pour rendre l'île plus vivante. Connaître?
ENOKI                            Bien qu'il s'avère qu'ils ont commencé à trop se multiplier et maintenant je dois les garder hors du jardin.
AARON                            Que dirais-tu de visiter les grottes un peu au nord d'ici?
AARON                            J'ai entendu dire qu'ils pourraient contenir des pierres précieuses qui nous-autres aideraient à faire de la pâte.
MAPLE                            Cela ne semble pas trop difficile.
MAPLE                            Hé... et merci pour la chambre.
AARON                            De rien.
ENOKI                            Oh, et si tu n'as pas encore rencontré Scout, c'est un mec super! Tu le trouveras caché dans le bunker à l'extérieur.

ENOKI                            Well... Première journée terminée! Je pense que ça a été une journée vraiment amusante.
MAPLE                            Tu connais quoi? Je suis d'accord. C'est la journée la plus intéressante que j'ai eue depuis longtemps.
AARON                            Allez tu changer d'avis sur ce que tu as dit sur le fait que tout cela était une mauvaise idée?
MAPLE                            Je ne suis ici que depuis un jour, donnez-moi un peu plus de temps jusqu'à ce que je tire mes conclusions finales.
AARON                            C'est dommage que nous-autres n'ayons qu'un seul canapé. Bien que nous-autres soyons très heureux que tu restes avec nous-autres jusqu'à ce que la nouvelle maison soit construite.
MAPLE Je dormais sur le canapé quand je vivais dans mon ancien appartement, donc ce n'est pas un problème pour moi non plus.
ENOKI                            Aw, as-tu dormi sur le canapé?
MAPLE                            C'était un magnifique canapé.
AARON                            Dans tous les cas, nous-autres devrions faire une pause. Je suis épuisé d'avoir coupé du bois toute la journée.
AARON                            A demain?
ENOKI                            Je suis sûr que nous-autres trouverons plus de choses à faire!
MAPLE                            Merci beaucoup pour tout. Je vais essayer d'apporter mon grain de sable sans être chiant tout le temps. Bonne nuit!
ENOKI                            Bonne nuit!

                                 Ugh... Ma tête... Pourquoi je ne peux pas dormir un clin d'oeil?
                                 Ne devrais tu pas pouvoir dormir après le trajet et une longue journée de dur labeur?
                                 Et d'où vient cette lumière de l'extérieur? C'est peut-être scout...
                                 Je devrais peut-être sortir et jeter un coup d'œil et voir ce que c'est.
                                 Mais quoi-? C'est un Mons de Plonj? Est-ce que tu tapes quelque chose?
                                 Je devrais aller voir avant que quelque chose de grave n'arrive.
                                 hum, hum... hum...
                                 HÉ! IDENTIFIEZ-VOUS OU JE FAIS UN BARBECUE AVEC VOTRE VISAGE!
                                 RUFUS AHHH?!
                                 OH, HUH... HUH, RUFUS! RUFUS THIBODEAUX!
                                 J'AI BESOIN DE MON VISAGE, S'IL VOUS PLAÎT NE LE BRÛLEZ PAS!    
MAPLE                            Oh, alors tu es /ce/ Rufus? Le cousin de Del, n'est-ce pas? Ravi, je suis Maple.
RUFUS                            Oh, es-tu un elfe du feu? J'aurais aimé le savoir avant d'essayer d'allumer ce feu.
MAPLE                            Qu'est-ce que tu fais ici?
RUFUS                            Je fais de la reconnaissance. J'ai un œil sur les îles Bill & Jim à côté.
RUFUS                            J'aime l'idée d'avoir un endroit rien que pour moi, sans avoir affaire à personne.
RUFUS                            Bien que je sois également préoccupé par la témérité de toute cette 'île privée'.
RUFUS                            D'ailleurs, tous ceux qui habitent près de Québec parlent avec cet accent ennuyeux...
MAPLE                            C'est quelque chose qui m'inquiétait aussi. Enoki est une gentille fille, mais parfois cet accent me tape sur les nerfs.
MAPLE                            Je commence aussi à sentir l'accent québécois se glisser dans la voix d'Aaron. Quelle galère.
MAPLE                            Au fait, qu'écrivez-vous?
RUFUS                            ...Vous allez penser que c'est idiot mais je fais un dessin.
MAPLE                            Regarde, après avoir vendu tous mes biens pour venir sur cette île, je t'assure que ton dessin n'est pas idiot.
RUFUS                            ...D'accord, c'est une grenouille. J'ai vu cette photo quand j'étais enfant, et cela me rend nostalgique pour une raison quelconque.
RUFUS                            Je ne me souviens pas à quoi ça ressemblait vraiment, alors je continue d'essayer. Je ne sais pas pourquoi, mais je sens que je dois le faire.
MAPLE                            Ouais, maintenant que tu l'expliques, ça a l'air un peu idiot, mais vas-y!
MAPLE                            Au fait... Avez-vous un endroit où dormir? Je ne peux pas t'offrir grand-chose, mais il fait froid dehors et nous-autres prenons une douche.
RUFUS                            J'apprécie, mais je pars demain matin. Et je n'ai définitivement pas envie de parler à qui que ce soit, même si je t'aimais bien.
MAPLE                            Ce fut un plaisir de trouver quelqu'un de constant avec qui discuter.

MAPLE                            Prends bien soin de toi, d'accord? Ravi de vous rencontrer, Rufus.
RUFUS                            Toi aussi! Ravi de vous rencontrer, Maple.

                                 Bonjour à tous, le moment est venu! Je suis Scout et me revoilà!

                                 C'est excitant d'avoir enfin un vrai public, mesdames et messieurs. Euh... monsieur.
                                 Aujourd'hui, c'est le 1er avril, et vous autres savez ce que cela signifie!
                                 Maple a déménagé sur l'île et nous-autres l'avons eue ici pendant une journée entière. Comme le temps passe!
                                 C'était une, euh, blague... Parce que c'est déjà le 1er avril, et il est avec nous-autres depuis un mois entier.
                                 Je-je ferais mieux de passer à autre chose... Bien! J'ai enfin pu récupérer le mot de passe de mon computer...!
                                 Oh, d'accord, d'accord, un autre fait. Trois nouvelles personnes s'installent sur l'île!
                                 Je ne suis pas sûr que nous-autres pourrons trouver de nouveaux insulaires potentiels sur Craigslist.
                                 Ils s'appellent Diana, Eleanor et Olivier. Et ils emménagent dans la nouvelle cabane au nord-ouest.
                                 Olivier a une serre dans le nord et Diana est une aspirante navigatrice compétente. Il s'occupera de conduire le navire.
                                 Alors accueillons-les chaleureusement!

                                 D'accord, c'est tout... Je suppose que je vous autres verrai tous plus tard. Merci beaucoup d'être là!

ENOKI                            Mmmmmm.... J'ai fait du pop-corn, mais je n'ai pas envie de me lever pour aller au micro-onde.
ENOKI                            Peux-tu aller les chercher, Maple? Est-ce qu'il te plaît?
MAPLE                            Ugh, je tiens toujours la chandelle autour de toi deux.
AARON                            Mais, c'est notre maison.
MAPLE                            Alors?
SCOUT’S COMPUTER LOGS:

                                 APRIL 1st, 2000 -                Scout log No. 48
                                 Scout TV broadcast actually had  a few viewers this time. I hope  they liked it.
                                 Maybe next time I'll finally haveenough people that I can host my very first Scout Expo.
                                 This dirt stuff is going really  slowly, and I've got funding, so
                                 I'm happy that I'm able to work  on stuff for fun.
                                 The 'bag of holding' isn't going to be done fora while, but the
                                 prototype shows lots of promise.
                                 Maybe it could work for that     request Aaron gave me when he
                                 wanted a way to race cars on the island.
                                 I could just stick a whole       racetrack in the pocket dimension
                                 so we don't have to tear the     whole place up.
                                 Of course, it has to be perfect. If he gets stuck there...
                                 Yeah, it's gotta be perfect.

                                 MAY 1st, 2000 -                  Scout log No. 68
                                 Two new villagers, one of them a little shady but Enoki seems to trust him.
                                 Apparently the other new guy is agreat chef, and his last name is Pizza.
                                 I've gotta figure out his real   name, my curiosity is gonna kill me.
                                 Rufus has been insufferable and  decided to interrupt Scout TV.
                                 I don't know if he's got some    kind of complex or something going on.
                                 Frankly enough, I'm a little     worried. Maybe I should check on him.
                                 Like, more than I'm supposed to.
                                 Apparently some company wants to store a bunch of gasoline over at his
                                 island. I found out when they    accidentally took some here.
                                 What's he gonna do with all that gasoline? We may never know.
                                 Hopefully everyone does okay thismonth. I'm having a lot of fun.
                                 Scout out. Hehe, 'scout out'.

                                 MARCH 29th, 2000 -               Scout log No. 45 (deleted)
                                 Gotta be the best day since I    moved over here from the Bill &
                                 Jim islands. I do NOT miss those islands.
                                 That Rufus guy was a real pain inthe patookas. Constantly
                                 yammering on about that          conspiracy stuff
                                 I hope he's doing fine by himselfover there.
                                 But man, that Maple girl... whew.I think she smiled at me for the
                                 first time since she came here.
                                 It probably doesn't mean anythingbut I haven't been able to sleep
                                 just thinking about it.
                                 She hasn't ever said anything to me that wasn't making fun of me
                                 but maybe she's just playing hard to get.
                                 I've seen how she talks to Aaron and Enoki, she's like that to    everyone.
                                 Mmm.. Maybe someday I'll figure  out how to talk to her. Maybe
                                 I'll make something that really  impresses her.
                                 She's never acts like she's      short interested in anything but she   likes food and books.
                                 Maybe it's not the same kinds,   but I like food and books too.
                                 Maybe she just likes bigger guys though, and I'm shaped like      Grimace from McDonald's.
                                 That's it. I'll invent a way to  get me into shape.
                                 But she SMILED at me.            Now, it was because I tripped on
                                 something, but maybe she thinks  I'm cute.
                                 I've gotta delete this log when  I'm done writing it.

                                 APRIL 29th, 2000 -               Scout log No. 65 (deleted)
                                 That new guy, man, I don't have aCHANCE with Maple.
                                 First off, apparently they know  each other? He calls her pizza   girl?
                                 I'm done for. Completely. Might  as well give up.
                                 Maybe I should learn to cook     something for once.
                                 I definitely need to get into    shape, for real.
                                 I guess it wouldn't do well to   bring it up to Guy.
                                 Maybe I'll just work on myself   and let it go unless someone     brings it up.
                                 ...Yeah.
                                 I need to stop writing these logsabout my lack of a love life.

                                 MARCH 30th, 2000 -               Scout log No. 46 (deleted)
                                 That Rufus guy was a real pain inthe patookas. Constantly
                                 yammering on about that          conspiracy stuff
                                 Those folks from the company sentme a real cryptic message today.
                                 Apparently they're not interestedin 'results' anymore, they just
                                 want me to install more surveillance equipment.
                                 Is it official? Maybe they want  Scout TV to be a real broadcast?
                                 I'm suspicious it's gotta do withthat Rufus guy.
                                 They keep asking me about him,   even though we don't work        together.
                                 It's like they wanna arrest him, but they're waiting for whatever he's inventing to be done, first.
                                 It wouldn't surprise me.
                                 Yeah, this log can't be left on  my PC.

                                 APRIL 30th, 2000 -               Scout log No. 66 (deleted)
                                 I've been thinking a lot about   the Apres flower lately.
                                 I can't help but wonder if that  Enoki girl took some. Her eyes...
                                 Well, I can never get a good     enough look to see if the 'ring' is there or not.
                                 But it'd explain so much.
                                 Actually, now that I think about it, after hearing about the, er..SECOND side effect..
                                 It might not be a bad idea to    keep an eye and see if anything  happens.
                                 I don't want anything bad to     happen to me or anyone else.
                                 We'll see.
                                 You know what? Screw you. You    don't deserve to hear what's     happening to the Tremblays.
                                 They're staying out of this and  I'm going to delete this log.

                                 TIME RAIDERS: GENESIS            a fan creation by                ICHABOD 'SCOUT' WILLIAMS
                                 The time for reckoning was upon  him, Jahn-Jahn Gazebo felt. It   was only a matter of time before
                                 Star Space Goblin Emperor Wizard would catch up to his planet. Butthe Time Raiders   were prepared.
                                 The squeebo-zeebos had warned himahead of time, so he and his bandwere ready.
                                 They were going to hide in plain sight by pretending to be a      different band - 'Space Raiders'.
                                 Jahn-Jahn had given his guitar   sword a new paint job.
                                 Nexus, his quipster sidekick, hadfashioned his keyboard to look
                                 like a computer keyboard, and    swapped out his Mondo Glasses    for a pair of normal sunglasses.
                                 Ninjette, their drummer and      ninja, had disguised her mondo
                                 nunchucks / drumsticks as a pair of chicken drumsticks. They      looked very delicious.
                                 The time had come. They decided  to swap genres. Country music waswhat they were going with.
                                 Soon enough, the Star Space      Goblin Emperor Wizard had landed on Sqeeb-Sqeeb 9.
                                 'AAALRIGHT!' he exclaimed, 'I AM SEARCHING FOR JAHN-JAHN GAZEBO!
                                 HIS SKULL WILL MEET MY WICKED    FIST OF EVIL!.. FOR EVIL!'
                                 'Not so fast, Star Space Goblin  Emperor Wizard!' said Jahn-Jahn, wearing a fake wig.
                                 'How do you know, random         civilian?' asked the Star Space
                                 Goblin Emperor Wizard, who did   not recognize his nemesis.
                                 'I wrote a song about it! Wanna  hear it? Here it goes!' And withthat, the song began.
                                 Because it was country music, it sucked so hard that all of his  goons died.
                                 The Star Space Goblin Emperor    Wizard himself was suspicious
                                 that it was actually them, but   Ninjette thought fast.
                                 She tossed one of the chicken    legs into his mouth, which he
                                 thought was delicious. It bought them enough time to leave.
                                 That's when they met a dude namedScout, who was a fantastic pilot who helped them escape.
                                 'Wow, Scout! You're such a great pilot!' said Jahn-Jahn. 'Do you  want to join the Time Raiders?'
                                 Scout immediately accepted, and  everyone lived happily ever      after.
                                 I can't believe this story got   rejected from the Time Raiders  script competition, it's perfect.

                                 TIME RAIDERS: NEO GENESIS DAWN   a fan creation by                ICHABOD 'SCOUT' WILLIAMS
                                 Jahn-Jahn Gazebo was sad.        Very sad.                        He felt a deep sadness.
                                 This is because he had accident- ally consumed the sadness pepper of Sector 9.
                                 'What is it, Jahn-Jahn?' asked   Scout, who was his first officer.
                                 'Peppers suck,' he replied.      He was right.
                                 They didn't go on an adventure   this time, since they let Scout  decide their destination.
                                 Scout is a very indecisive       individual, you see.
                                 In fact, Scout was getting both  writer's block and a horrible    pain in his wrist.
                                 So, the Star Space Goblin Emperordecided to randomly give up and  give them his ship.
                                 All evil in the universe was     magically zapped away and all    was well the end I'm tired.
                                 ...
                                 I'm just not cut out to be a     writer, am I? Far too lazy.

                                 Huh... I never thought I'd       actually beat the game.
                                 Maybe I should do something aboutit.
                                 Eh, later.
                                 1 de Abril, 2000 -               Registro de Exploración No. 48
                                 La transmisión de Scout TV tuvo  algunos espectadores esta vez.   Espero que les haya gustado.
                                 La próxima vez puede que tenga   los suficientes como para hacer  el primer Expo Scout.
                                 Las cosas avanzan muy lentamente pero tengo financiación, así que
                                 estoy feliz de poder trabajar en esto por mera diversión.
                                 El 'Bolsillo Mágico' no estará   preparado hasta pasado un        tiempo, aunque el
                                 prototipo parece prometedor.
                                 Tal vez podría ser útil para     aquella petición que me hizo Aaron
                                 acerca de hacer carreras de      autos en la isla.
                                 Podría meter toda una pista de   carreras en la dimensión del     bolsillo mágico.
                                 Así no tendríamos por qué dejar  todo el lugar hecho un desastre.       
                                 Claro que todo ha de salir bien. Pero si se quedase pillado...
                                 Nah, esto irá sobre ruedas.
1er avril 2000 - Carnet d'exploration n° 48
                                 L'émission Scout TV a eu quelques téléspectateurs cette fois. J'espère que tu l'a aimé.
                                 La prochaine fois, j'en aurai peut-être assez pour faire la première expo scoute.
                                 Les choses avancent très lentement mais j'ai des financements donc
                                 Je suis heureux de pouvoir travailler dessus juste pour le plaisir.
                                 Le 'Magic Pocket' ne sera pas prêt avant un certain temps, bien que le
                                 le prototype semble prometteur.
                                 Peut-être que cela pourrait être utile pour cette demande qu'Aaron m'a faite.
                                 de faire des courses de voitures sur l'île.
                                 Je pourrais intégrer une piste de course entière dans la dimension magique de la poche.
                                 De cette façon, nous-autres n'aurions pas à laisser tout l'endroit en désordre.
                                 Bien sûr, tout doit bien se passer. Mais, s'il se fait prendre...
                                 …eh, it’ll be fine.

                                 1 de Mayo, 2000 -                Registro de Exploración No. 68
                                 Han venido dos nuevos aldeanos,  uno de ellos es un poco turbio   pero Enoki confía en él.
                                 Aparentemente el otro chico nuevoes un gran chef, su supuesto     apellido es Pizza.
                                 Debo descubrir su nombre real,   la curiosidad me está matando.
                                 Rufus ha sido insufrible y ha    decidido interrumpir Scout TV.
                                 No sé si tiene algún tipo de     problema o si le ocurre conmigo.
                                 Francamente hablando, estoy un   poco preocupado. Quizá deba      mantenerlo bajo vigilancia.
                                 Osea, vigilarlo aún más que      antes.
                                 Parece ser que alguna compañía   quiere almacenar un montón de    gasolina en la isla.
                                 Me di cuenta cuando ellos        la trajeron accidentalmente.
                                 ¿Qué planean hacer con toda esa  gasolina? 	Quizá nunca lo sepamos.
                                 Esperemos que todos estén bien   este mes. Me estoy divirtiendo   mucho con ellos.
                                 Scout out. Jeje, 'scout out'.
1 mai 2000 - Carnet d'exploration n° 68
                                 Deux nouveaux villageois sont arrivés, un d'eux est un peu louche mais Enoki lui fait confiance.
                                 Apparemment, l'autre nouveau gars est un grand chef, son nom de famille supposé est Pizza.
                                 Je dois trouver son vrai nom, la curiosité me tue.
                                 Rufus a été insupportable et a décidé d'arrêter Scout TV.
                                 Je ne sais pas s'il a un problème quelconque ou si cela m'arrive.
                                 Franchement, je suis un peu inquiet. Je devrais peut-être le garder sous surveillance.
                                 Je veux dire, regardez-le encore plus qu'avant.
                                 Il semble qu'une entreprise veuille stocker beaucoup d'gasoline sur l'île.
                                 Je l'ai découvert quand ils l'ont accidentellement amenée.
                                 Qu'est-ce qu'ils comptent faire de toute cette gasoline? Nous ne le saurons peut-être jamais.
                                 Espérons que tout le monde va bien ce mois-ci. Je m'amuse beaucoup avec eux.
                                 Scout out. Hehe, 'scout out'.

                                 29 de Marzo, 2000 -              Reg. de Exploración N45 (Borrado)
                                 Desde que vine de las islas      Bill & Jim, este ha sido uno de  mis mejores días.
                                 Definitivamente no extraño       aquellas islas.
                                 Aunque ese tal Rufus ha sido Comouna patada en las pelotas.       Siempre dando la lata
                                 con todas esas ideas             conspiranoicas suyas.
                                 Viendo que tiende a aislarse,    espero que le vaya bien estando  solo.
                                 Pero tío, esa tal Maple... Whew. Creo que me ha sonreído por      primera vez
                                 Desde el primer momento en el    que coincidimos aquí.
                                 Probablemente no signifique nada pero no he sido capaz de         conciliar el sueño
                                 cada vez que pienso en ello.
                                 Nunca me ha dicho nada más allá  de burlarse de mí...
                                 Pero tal vez sólo está jugando   a hacerse la dura conmigo.
                                 He visto cómo trata a Aaron y    Enoki, ella es así con todos.
                                 Mmm... Quizá algún día dé con la clave de cómo acercarme a ella.
                                 Haré algo que pueda              impresionarle.
                                 Actúa como una pasota a la que nole interesa nada, pero parece    agradarle los libros y comer.
                                 Quizá no me guste lo mismo que   a ella, pero también me agradan  los libros y la comida.
                                 Pero sería un problema si le     atraen los mazados, soy más bien como Grimace de McDonald's.
                                 Aunque bueno, podría inventar    algo para ponerme en forma.
                                 Después de todo ella ME SONRIÓ.  Puede que sea porque me tropecé
                                 con algo, pero igual piensa que  soy mono.
                                 Voy a borrar este registro.      No sé ni por qué lo he escrito.
29 mars 2000 - Règlement sur l'exploration N45 (supprimé)
                                 Depuis que je viens des îles Bill & Jim, cela a été l'un de mes meilleurs jours.
                                 Ces îles ne me manquent définitivement pas.
                                 Bien que ce gars de Rufus ait été une sorte de coup de pied dans les couilles. toujours donner la canette
                                 avec toutes vos idées de complot.
                                 Vu qu'il a tendance à s'isoler, j'espère qu'il se porte bien tout seul.
                                 Mais mec, ce Maple... Ouf. Je pense qu'il m'a souri pour la première fois
                                 Dès le premier instant où nous-autres sommes rencontrés ici.
                                 Ça ne veut probablement rien dire mais je n'ai pas réussi à m'endormir
                                 chaque fois que j'y pense.
                                 Il ne m'a jamais rien dit à part me moquer de moi...
                                 Mais peut-être qu'elle joue juste avec moi.
                                 J'ai vu comment elle traite Aaron et Enoki, elle est comme ça avec tout le monde.
                                 Hmm... Peut-être qu'un jour je trouverai comment l'aborder.
                                 Je ferai quelque chose qui pourra t'impressionner.
                                 Elle agit comme une gaffe qui ne s'intéresse à rien, mais semble aimer les livres et manger.
                                 Je ne l'aime peut-être pas de la même manière, mais j'aime aussi les livres et la nourriture.
                                 Mais ce serait un problème si tu aimes les masses, je suis plus comme Grimace de McDonald's.
                                 Quoique bon, je pourrais inventer quelque chose pour me mettre en forme.
                                 Après tout, elle m'a souri. C'est peut-être parce que j'ai trébuché
                                 avec quelque chose…
                                 Je vais supprimer cet enregistrement. Je ne sais même pas pourquoi je l'ai écrit.
Dialogue before the boat minigame

CAP'N NICHOLAS                   Ahoy there, lass! Are ye ready   fer yer a voyage?
DIANA                            Aye aye, Captain!
CAP'N NICHOLAS                   Just remember what I told ye' -  watch out fer the rocks, and     watch yer speed!
DIANA                            Aye aye, sir!
CAP'N NICHOLAS                   ¡Yepa, señorita! ¿Está’ prepará  pa’l viaje?
DIANA                            ¡Sí, capitán!
CAP'N NICHOLAS                   Recuerda lo que te’ dicho -      ¡Cuidaíto con la’ piedra’ y      atenta a la velosidá’!
DIANA                            ¡Sí, capitán!
CAP'N NICHOLAS                   Ouais, mademoiselle! Êtes-vous prêt pour le voyage?
DIANA                            Oui, capitaine!
CAP'N NICHOLAS                   Rappelez-vous ce que je vous ai dit - Soyez prudent avec la pierre et faites attention à la vitesse!
DIANA                            Oui, capitaine!!

Incidental dialogue

MAPLE                            Enoki, there's no window.
ENOKI                            Uh-huh?
MAPLE                            What happens if someone tries-
MAPLE                            to break in?
ENOKI                            Aaron punches 'em.
ENOKI                            In the face.
MAPLE                            He's not here, though.
ENOKI                            Then I'll punch 'em.
MAPLE                            I.... Hmm. Alright, then.

You see a pot.
You feel compelled to smash it.
However, this is not possible.
You feel strangely disappointed.

MAPLE                            Hey, let's head out. I don't want
MAPLE                            to wake him up.
ENOKI                            I dunno, it doesn't matter,
ENOKI                            there's no way he'll wake up.
ENOKI                            He likes the light on, too.
MAPLE                            I thought you didn't have
MAPLE                            electricity..?
ENOKI                            Oh, we do- just that one plug.
ENOKI                            It's a very important plug.
MAPLE                            You sure you like this place?
ENOKI                            You gonna come here and insult
ENOKI                            my house?
MAPLE                            Well, when you put it THAT way...
ENOKI                            Uh huh, that's what I thought.
MAPLE                            Je m'excuse.
ENOKI                            Merci.
MAPLE                            But when you both move in with me
MAPLE                            don't say I didn't warn y'all.

ENOKI                            Y'know, back when Del was my
ENOKI                            nanny, my parents gave her like
ENOKI                            three different rooms she could
ENOKI                            stay in. I don't think she ever
ENOKI                            slept anywhere but the tub.
MAPLE                            That actually sounds pretty nice.
ENOKI                            Yeah, I tried it but my skin
ENOKI                            didn't like it very much.

MAPLE                            Enoki, this one's locked.
ENOKI                            Oh. Yeah, I think that's
ENOKI                            the kitchen. We don't know where
ENOKI                            the key is.
MAPLE                            So how do you eat??
ENOKI                            We make most of our food over the
ENOKI                            big fire pit!
MAPLE                            You two, I *swear*....

ENOKI                            Isn't he so cute when he
ENOKI                            sleeps like that? <3
MAPLE                            You've been married for, what,
MAPLE                            a few months now?
MAPLE                            Aren't you supposed to be at the
MAPLE                            stage where neither of you talk
MAPLE                            to each other at meals and both
MAPLE                            of you've gained ten pounds?
ENOKI                            Huh, I think I've lost weight.
MAPLE                            I guess I don't get it.
ENOKI                            Just cos you always get in
ENOKI                            fights with your ex-boyfriends
ENOKI                            doesn't mean every couple's like
ENOKI                            that, tu connais.
ENOKI                            I mean, you've got this nasty
ENOKI                            habit of-
MAPLE                            You finish that sentence, and
MAPLE                            I'll burn your eyebrows off.
ENOKI                            ......doing that.

ENOKI                            Nous sommes ici!
ENOKI                            The bookshelf room.
MAPLE                            You weren't kidding about there
MAPLE                            literally being just a bookshelf
MAPLE                            room, were you?
ENOKI                            Bon, so I can't move it and Aaron
ENOKI                            can't either, so I was wondering,
ENOKI                            how about using that elf magic?
MAPLE                            Let me get this straight...
MAPLE                            You want me to *burn* a perfectly
MAPLE                            good bookshelf?
ENOKI                            Yeah! I wanna see if there's a
ENOKI                            secret passage behind it or
ENOKI                            somethin', y'know?
MAPLE                            I refuse. This is ridiculous.
MAPLE                            These are perfectly good books.
ENOKI                            Most are rotting away, so
ENOKI                            it's probably best that they get
ENOKI                            burned. I checked.
MAPLE                            Are you sure?
ENOKI                            Absolutely.
MAPLE                            Alright... I'll make a deal.
MAPLE                            I'll burn this, but you need to
MAPLE                            save at least one book. //j'ai compris?
MAPLE                            J'ai compris? Oui?
ENOKI                            Oui!
ENOKI                            ....alright, I got my book.
ENOKI                            Remember, use the 'R' trigger
ENOKI                            to send out a bolt of fire!
MAPLE                            ...What are you talking about??
ENOKI                            Huh? Oh, nothing

MAPLE                            ....
ENOKI                            Well, there's no passage.
MAPLE                            You don't say.
ENOKI                            That's weird.
MAPLE                            Enoki... Look here.
MAPLE                            I guess it doesn't make any sense
MAPLE                            to be angry, so I won't be, but..
MAPLE                            You need to stop being like this.
MAPLE                            You and Aaron just spent all this
MAPLE                            money on a barely furnished
MAPLE                            castle without basic faculties
MAPLE                            for what? So you could play like
MAPLE                            you're a princess? While I'm over
MAPLE                            in Carolina, sacrificing the best
MAPLE                            parts of my life for an apartment
MAPLE                            with the bare essentials?
MAPLE                            Enoki... Please.
MAPLE                            I don't want to be the bad guy.
MAPLE                            I know you didn't really have a
MAPLE                            childhood or parents, I get it.
MAPLE                            That's me too.
MAPLE                            But you can't keep going on like
MAPLE                            this. Do you understand?
ENOKI                            I do understand.
MAPLE                            It's 5:00 in the morning, I'm
MAPLE                            going back to bed. I'll see y'all
MAPLE                            in the morning, oui?
ENOKI                            Oui..
MAPLE                            Hey, don't beat yourself up about
MAPLE                            it. S'il te plait.. Bonne nuit.
ENOKI                            Bonne nuit..

MAPLE
    (Every single one of these are   Enoki's, aren't they?)
    (Of course Aaron would pick up   around here.)
    (They're so different... How on  earth are they not fighting-
    -all the time? I don't get it.)
    (If I had a boyfriend, I'd make  him pick up these clothes-
    -immediately.)
    

ENOKI
    (If I knew Maple was coming so   soon I probably would'a cleaned
    -these up a little sooner....)
    (Maybe I can pick 'em up now and she won't notice.)
    (Then again, maybe she already   saw it and is already judging.)
    (..This one's cute enough, maybe I'll just leave it on the floor-
    -and wear it tomorrow.)
    

AARON
    (Enoki wasn't this messy when we lived in the castle.)
    (Maybe she thinks we're finally  moved in for good, so she-
    -feels comfortable here.)
    (I know it's probably too soon to call, but Aaron Tremblay-
    -you've done it. You've got your own place, and you've got yourself-
    -a wife to leave her clothes on  the floor.)
    (I can't think of anything else  I could want, now.)
    (Well.....                       I miss my car.)
    (Maybe I'll talk to Scout about  putting in a racetrack.)
    
OTHERS
    (Yeah, I definitely need to not  be here.)
    
MAPLE
(At least when they were living  in that castle, their bed was in-
-the center of the room. What's  this supposed to be?)
(Who's shoved up awkwardly in thecorner? Aaron probably.)
(I swear, that girl is going to  give him grey hairs ten years    early.)

ENOKI
(I'm so glad I don't have'ta     sleep in the middle of the room.)
(Rolling over off the bed onto   that stone really really hurt.)
(Now I getta roll either into    the wall or into Aaron.)
(I'm so glad he doesn't seem to  mind that much.)

AARON
(Maple isn't gonna be happy when she sees this room.)
(I remember when she used to be  so easy-going...)
(She's just so frustrating to be around these days.)
(Maybe she shouldn't have come.  Every time I try to do something-
-to help her out, she just spits all over me and pouts.)
(Maybe she'll get tired of       living here and just go home.)
(Maybe she's right. Maybe I'm    just living Enoki's fantasy.)
(But Enoki's the first bit of    happiness I've had in years.)
(Maybe we'll both change...      I hope something changes.)

OTHERS
(I probably shouldn't be in here uninvited...)

MAPLE
(There's no way I'm going to ever admit it, but...)
(It's nice staying with them. I  keep forgetting how much I)
(miss staying with somebody.)

ENOKI
(Y'know, I wish I could go back  in time and talk to little me.)
(She would NOT BELIEVE what this year's been like.)
(I.. don't think my parents know I'm here.)
(Where the heck do they think I  am I wonder, huh.)

AARON
(I really, really need to get    Maple her own place.)
(I didn't figure she'd actually  pull her weight, but...)
(With all that spelunking, we've made enough to break even.)
(I'm surprised she hasn't really been asking for a new place.)
(Maybe she doesn't really like   staying by herself.)
(I really don't want to have to  make another house.)
(I'll talk to that Olivier guy   and see what he can do.)
(He seems handy enough.)

OTHERS
(Yep, that's a room.)

OLIVIER
(Definitely like all the sunlightin here.)
(Could use a plant or two.)

ELEANOR
(This reminds me so much of Vee'sparents' house.)
(I hope they're trustworthy      people.)

DIANA
(Ok, I like these people.)
(They make me feel organized.)

MAPLE
(Thank goodness, that new guy..  er.. guy is a cook.)
(Maybe gumbo every day won't be  as heavy when it's not mine.)
(Maybe he's got a good sense of  humor, too.)
(Ugh, what's wrong with me.. I'm getting excited to meet people?)
(What, am I sick? Am I becoming..personable? Gross.)

ENOKI
(Y'know, this room hasn't changed in a bit.)
(What if I moved the bed to the  other side of the room?)
(Hmm, then it'd be harder to hideclothes from guests.)
(I gotta pick those up.. eh...   later, later is good.)

AARON
(Well, there goes the last chance for Maple to take the cabin.)
(As long as Enoki thinks its     sweet that Maple wants to stay,)
(This isn't going to be my house.What happened to her being so)
(independent and proud of it?    Ugh.. generousity leech.)
(And now Enoki's onto the fact   that I'm a bit upset.)
(Crap.. Now I'm sounding like    Maple myself.)
(Do all siblings sound like this?Heck if I'd know.)
(I don't have any friends.)

OLIVIER
(Aaron's birthday is coming up.. plants could be a good gift.)

DIANA
(Definitely like all the light   in here.)
(Could use a plant or two.)

OTHERS
(It probably isn't my business tobe here.)

MAPLE                            So, uh, what's the book?
AARON                            Oh, that's mine.
AARON                            You know I'm not a fiction guy,
AARON                            But Enoki is stubborn.
ENOKI                            You ever heard'a Yellow?
ENOKI                            It's kinda fun, I got Aaron into it.
MAPLE                            ...does this have pictures?
MAPLE                            Do you still read picture books?
ENOKI                            It's got cigarettes in it though!
ENOKI                            That means its for kids AND      adults.
MAPLE                            Huh, they make books like that?

MAPLE                            Enoki, no hay ventana.
ENOKI                            ¿Uh-huh?
MAPLE                            ¿Y qué pasaría si alguien
MAPLE                            intentara colarse?
ENOKI                            Aaron le daría una somanta de    palos.
ENOKI                            Hasta dejarle la cara hecha un   cristo.
MAPLE                            Pero él no está aquí ahora mismo.
ENOKI                            Entonces seré yo quién le dé la  paliza.
MAPLE                            Eh.... Hmm. Eso está bien,       supongo.
MAPLE                            Enoki, il n'y a pas de fenêtre.
ENOKI                            Euh-hein?
MAPLE                            Et si quelqu'un
MAPLE                            tentera-t-il de se faufiler?
ENOKI                            Aaron lui donnerait une raclée.
ENOKI                            Jusqu'à ce qu'il quitte son visage comme un Christ.
MAPLE                            Mais il n'est pas là en ce moment.
ENOKI                            Alors je serai celui qui le battra.
MAPLE                            Euh... Hum. C'est bien, je suppose.

Ves una vasija.
Sientes que deberías destruirla.
Pero no puedes hacer eso.
Te invade una extraña decepción.
Vous voyez un pot.
Tu sens que tu devrais la détruire.
Mais vous ne pouvez pas faire ça.
Une étrange déception vous envahit.

MAPLE                            Mejor nos vamos. No me gustaría
MAPLE                            despertarle.
ENOKI                            Nah, no creo que pase nada.
ENOKI                            Despertar a este dormilón es     imposible.
ENOKI                            También le gusta dormir con las  luces encendidas.
MAPLE                            Pensaba que no teníais
MAPLE                            electricidad...
ENOKI                            Sí que tenemos, pero ese es el   único enchufe.
ENOKI                            Es un enchufe muy importante.
MAPLE                            ¿De verdad te gusta este sitio?
ENOKI                            ¿Acaso has venido sólo para 
ENOKI                            ponerle pegas a mi casa?
MAPLE                            No, QUÉ VA, en absoluto...
ENOKI                            Uh huh, ya decía yo.
MAPLE                            Je m'excuse.
ENOKI                            Merci.
MAPLE                            Pero cuando os vengáis conmigo.
MAPLE                            No me digas que no os lo advertí
MAPLE                            Nous ferions mieux d'y aller.
ENOKI                            C'est bon. Il dort avec la lumière allumée.
MAPLE                            Je pensais que ta prise électrique était à l'extérieur?
ENOKI                            Well, il y a aussi celui-ci. C'est le seul autre. C'est très important, tu vois.
MAPLE                            Aimes tu vraiment cet endroit?
ENOKI                            Es-tu ici juste pour te plaindre de ma maison?
MAPLE                            Non, pas du tout...
ENOKI                            Euh hein, je disais.
MAPLE                            Je m'excuse.
ENOKI                            Merci.
MAPLE                            Mais quand tu viens avec moi,
MAPLE                            Ne me dis pas que je ne t'avais pas prévenu.

ENOKI                            ¿Sabes? Cuando Del era mi 
ENOKI                            niñera, mis padres le ofrecieron
ENOKI                            tres habitaciones diferentes en 
ENOKI                            las que quedarse. Pero aún así
ENOKI                            Del siempre dormía en la bañera.
MAPLE                            Pues eso no suena del todo mal.
ENOKI                            Ya, yo lo intenté pero a mi piel
ENOKI                            no le gustó mucho la idea.
ENOKI                            Le savais tu? Quand Del était ma baby-sitter, mes parents lui ont proposé trois chambres différentes pour rester. Mais Del dormait toujours dans la baignoire.
MAPLE                            Well, ça ne sonne pas mal du tout.
ENOKI                            Ouais, j'ai essayé mais ma peau n'a pas trop aimé l'idée.

MAPLE                            Enoki, esto está bloqueado.
ENOKI                            Oh. Sí, creo que eso es la
ENOKI                            cocina. Pero no sabemos dónde
ENOKI                            podría estar la llave.
MAPLE                            ¿Y entonces cómo coméis?
ENOKI                            ¡Solemos cocinarlo todo en
ENOKI                            una gran hoguera!
MAPLE                            ¡Me vais a matar de un disgusto!
MAPLE                            Enoki, c'est verrouillé.
ENOKI                            Oh. Oui, je pense que c'est la cuisine. Mais nous-autres ne savons pas où se trouve la clé.
MAPLE                            Et puis comment manger tu?
ENOKI                            Nous cuisinons généralement tout sur un grand feu de joie!
MAPLE                            Tu vas me tuer de dégoût!

ENOKI                            ¿No está monísimo cuando se
ENOKI                            queda dormido? <3
MAPLE                            ¿No han pasado ya varios meses
MAPLE                            desde que os casásteis?
MAPLE                            ¿No deberíais estar ya en esa
MAPLE                            fase en la que ninguno se dirige
MAPLE                            la palabra cuando coméis juntos
MAPLE                            y habéis ganado unos 5 kilos?
ENOKI                            Huh,Yo creo que he perdido peso.
MAPLE                            Creo que no entiendo lo vuestro.
ENOKI                            Sólo porque estés siempre
ENOKI                            peleándome con tus ex-novios no
ENOKI                            significa que todas las parejas
ENOKI                            tengan que ser así, tu connais.
ENOKI                            A ver, es que siempre tienes ese 
ENOKI                            hábito de-
MAPLE                            Como acabes esa frase te voy a-
MAPLE                            Te voy a quemar las pestañas.
ENOKI                            ...Atrévete si eres capaz.
ENOKI                            N'est-il pas si mignon quand il s'endort? <3
MAPLE                            Cela ne fait pas plusieurs mois que tu es marié?
MAPLE                            Ne devrais tu pas déjà être dans cette phase où tu ne tu parlez pas quand tu mangez ensemble et que tu avez pris environ 5 kilos?
ENOKI                            Euh, je pense que j'ai perdu du poids.
MAPLE                            Je crois que je ne comprends pas ton truc.
ENOKI                            Ce n'est pas parce que tu discutes toujours avec tes ex-petits amis que tous les couples doivent être comme ça, tu savez.
ENOKI                            Voyons, tu as toujours cette habitude de-
MAPLE                            Pendant que tu finissez cette phrase,
MAPLE                            Je vais te brûler les cils.
ENOKI                            ...cette.

ENOKI                            Nous sommes ici!
ENOKI                            ¡Aquí está la gran estantería!
MAPLE                            Veo que no estabas de broma con
MAPLE                            eso de la biblioteca, y tampoco
MAPLE                            con lo de la estantería...
ENOKI                            Bon, nosotros no hemos logrado
ENOKI                            moverla. ¿Puedes hacerme el 
ENOKI                            favor de usar tu magia élfica?
MAPLE                            A ver si lo capto...
MAPLE                            ¿Quieres que *queme* una 
MAPLE                            estantería bien conservada?
ENOKI                            Quiero comprobar si hay algún
ENOKI                            pasadizo secreto detrás de ella
ENOKI                            o algo por el estilo, ¿sabes?
MAPLE                            Me niego. Esto es ridículo.
MAPLE                            Además esos libros se ven bien.
ENOKI                            No están en tan buen estado.
ENOKI                            Ya los revisé. Que ardan sería 
ENOKI                            lo mejor que les pueda pasar. 
MAPLE                            ¿Estás segura de ello?
ENOKI                            Completamente.
MAPLE                            Ok, hagamos un trato entonces.
MAPLE                            Quemaré esto, pero debes salvar
MAPLE                            al menos un libro. //j'ai compris?
MAPLE                            ¿J'ai compris? ¿Oui?
ENOKI                            ¡Oui!
ENOKI                            ... Vale, he tomado un libro.
ENOKI                            Recuerda, ¡usa el gatillo 'R'
ENOKI                            para lanzar una bola de fuego!
MAPLE                            ¿...De qué estás hablando?
ENOKI                            ¿Huh? Oh, no es nada.
ENOKI                            Nous sommes ici!
ENOKI                            Voici la grande bibliothèque!
MAPLE                            Je vois que tu ne plaisantais pas à propos de la bibliothèque...
ENOKI                            Bon, nous-autres n'avons pas pu la déplacer. Pourrais tu me rendre service et utiliser ta magie elfique?
MAPLE                            Voyons si je comprends...
MAPLE                            Tu veux que je *brûle* une bibliothèque bien conservée?
ENOKI                            Je veux vérifier s'il y a un passage secret derrière elle ou quelque chose comme ça, tu connais?
MAPLE                            Je refuse. Ça c'est ridicule.
MAPLE                            En plus, ces livres ont l'air bien.
ENOKI                            Ils ne sont pas en si bon état.
ENOKI                            Je les ai déjà vérifiés. Qu'ils brûlent serait la meilleure chose qui puisse leur arriver.
MAPLE                            en es-tu sûr?
ENOKI                            Complètement.
MAPLE                            OK, faisons un marché alors.
MAPLE                            Je vais brûler ça, mais tu dois sauver au moins un livre.
MAPLE                            J'ai compris? Oui?
ENOKI                            Oui! ... Ok, j'ai pris un livre.
ENOKI                            N'oubliez pas, utilisez la gâchette 'R' pour lancer une boule de feu!
MAPLE                            ...De quoi parles-tu?
ENOKI                            Hein? Oh, it’s nothing.

MAPLE                            ....
ENOKI                            Bueno, pues no hay pasadizo.
MAPLE                            Vaya, no me digas.
ENOKI                            Qué extraño.
MAPLE                            A ver, Enoki...
MAPLE                            Supongo que no tiene ningún
MAPLE                            sentido enfadarse contigo, pero
MAPLE                            deberías dejar de actuar así.
MAPLE                            Tú y Aaron os habéis gastado un
MAPLE                            dineral en un castillo sin
MAPLE                            amueblar ni facultades básicas.
MAPLE                            ¿Por qué? ¿Para que puedas jugar
MAPLE                            a hacerte la princesa? Mientras 
MAPLE                            haces eso, yo sacrifico toda 
MAPLE                            mi vida personal manteniendo el
MAPLE                            apartamento de Carolina con sólo
MAPLE                            lo esencial. Enoki... Por favor.
MAPLE                            No quiero parecer la mala aquí.
MAPLE                            Entiendo que no has tenido 
MAPLE                            una buena infancia estando tan
MAPLE                            alejada de tus padres...
MAPLE                            Pero no puedes seguir portándote
MAPLE                            de esta forma. ¿Lo entiendes?
ENOKI                            Lo entiendo.
MAPLE                            Son las 5:00 de la mañana, voy
MAPLE                            a volver a la cama. Os veré por
MAPLE                            la mañana, ¿oui?
ENOKI                            Oui...
MAPLE                            No te martirices pensando en
MAPLE                            ello. S'il te plait, Bonne nuit.
ENOKI                            Bonne nuit...
MAPLE                            ....
ENOKI                            Eh bien, il n'y a pas de passage.
MAPLE                            Wow, ne me dis rien.
ENOKI                            Comme c'est étrange.
MAPLE                            Voyons, Enoki...
MAPLE                            Je suppose que ça ne sert à rien de se fâcher contre toi, mais tu devrais arrêter d'agir comme ça.
MAPLE                            Toi et Aaron avez dépensé une fortune dans un château non meublé sans capacités de base.
MAPLE                            Pourquoi? Alors tu peux jouer à la princesse? Pendant que tu fais ça, je sacrifie toute ma vie personnelle en gardant l'appartement de Carolina vide avec le strict nécessaire. Enoki... S'il vous plaît.
MAPLE                            Je ne veux pas ressembler au méchant ici.
MAPLE                            Je comprends que tu n'aies pas eu une bonne enfance étant si loin de tes parents...
MAPLE                            Mais tu ne peux pas continuer à te comporter comme ça. You get it?
ENOKI                            Je comprends.
MAPLE                            Il est 5 heures du matin, je retourne me coucher. Je te verrai demain matin, oui?
ENOKI                            Oui...
MAPLE                            Ne culpabilise pas en y pensant. S'il te plait, bonne nuit.
ENOKI                            Bonne nuit...

MAPLE
    (Todas y cada una de estas       prendas son de Enoki, ¿no?)
    (Claro que Aaron recogería       todas las suyas.)
    (Son tan distintos... Que no     entiendo cómo lo hacen para
    no pelearse todo el tiempo.      No consigo comprenderlo.)
    (Si tuviera novio, le            obligaría a recoger toda su
    ropa inmediatamente.)
MAPLE
     (Chacun de ces vêtements est celui d'Enoki, n'est-ce pas?)
     (Bien sûr, Aaron collectionnait tout le sien.)
     (Ils sont si différents... Je ne comprends pas comment ils arrivent à ne pas se battre tout le temps. Je ne peux pas comprendre.)
     (Si j'avais un boyfriend, je le forcerais à ramasser tous ses vêtements immédiatement.)
    

ENOKI
    (Si hubiera sabido que Maple iba a venir tan pronto, habría
    comenzado a limpiar un poco      antes....)
    (Tal vez no se dé cuenta si me   pongo a recoger ahora)
    (Aunque igual ya lo ha visto     todo y está juzgándome por ello)
    (...Este es muy mono, quizá lo   deje en el suelo y me lo ponga
    mañana.)
ENOKI
     (Si j'avais su que Maple arrivait si tôt, j'aurais commencé à nettoyer un peu plus tôt...)
     (Peut-être que tu ne remarquez pas si je commence à ramasser maintenant)
     (Bien qu'il ait déjà tout vu et qu'il me juge pour ça)
     (... Celui-ci est mignon, peut-être que je le porterai demain.)
    

AARON
    (Enoki no era tan desastrosa     cuando vivíamos en el castillo.)
    (Puede que piense que ya nos     hemos mudado de forma definitiva y
    empieza a sentirse más cómoda.)
    (Aunque seguramente sea pronto   para decirlo, Aaron Tremblay,
    lo has logrado. Has conseguido   un hogar propio y una esposa
    que deja sus prendas tiradas     por el suelo.)
    (No puedo pensar en otras cosas  que pueda querer ahora mismo.)
    (Bueno.....                      Extraño mi coche.)
    (Tal vez hable con Scout para    poner una pista de carreras.)
AARON
     (Enoki n'était pas un tel gâchis quand nous-autres vivions dans le château.)
     (Elle peut penser que nous-autres avons évolué pour de bon et commence à se sentir plus à l'aise.)
     (Bien qu'il soit probablement trop tôt pour le dire, Aaron Tremblay,
     vous avez réussi. Tu as une maison à toi et une femme
     qui laisse traîner ses vêtements par terre.)
     (Je ne peux penser à rien d'autre que je pourrais vouloir en ce moment.)
     (Well... ma voiture me manque.)
     (Peut-être parler à Scout de la mise en place d'une piste de course.)

    
OTHERS
    (Sí, definitivamente no debería  estar aquí.)
LES AUTRES
    (Oui, ça ne devrait certainement pas être ici.)
    
MAPLE
(Al menos cuando vivían en el    castillo, su cama estaba en
el centro de la habitación.      ¿Qué se supone que es esto?)
(¿Quién ha podido empujar la     esquina? Probablemente Aaron.)
(Te juro que esa chica va a      sacarle las canas 10 años antes.)
MAPLE
(Au moins quand ils vivaient dans le château, leur lit était au centre de la pièce. Qu'est-ce que c'est censé être?)
(Qui aurait pu pousser le coin? Probablement Aaron.)
(Je jure que cette fille va lui enlever les cheveux gris 10 ans plus tôt.)

ENOKI
(Me alegra no tener que dormir   en medio de la habitación.)
(Caer rodando de la cama en ese  suelo de piedra dolía un montón.)
(Ahora podré rodar tranquila     hacia el muro o hacia Aaron.)
(Me alegra mucho que a él no le  importe eso demasiado.)
ENOKI
(Je suis content de ne pas avoir à dormir au milieu de la pièce.)
(Rouler du lit sur ce sol en pierre faisait très mal.)
(Maintenant, je peux rouler en toute sécurité vers le mur ou vers Aaron.)
(Je suis tellement content que cela ne le dérange pas trop.)

AARON
(Maple no estará feliz cuando    vea la habitación.)
(Recuerdo cuando ella solía ser  más tranquila...)
(Ahora mismo es un poco          frustrante tenerle cerca.)
(Quizá ella no tendría que haber venido. Cada vez que trato de
ayudarle, lo único que hace es   quejarse y pagarla conmigo.)
(Puede que se aburra de vivir    aquí y vuelva a su casa.)
(O quizá tenga razón y solo estoyviviendo la fantasía de Enoki.)
(Pero Enoki ha sido la única     felicidad que he tenido en años.)
(Tal vez algo cambie... Espero   que ambos cambiemos a mejor.)
AARON
(Maple ne sera pas contente quand elle verra la pièce.)
(Je me souviens quand elle était plus calme...)
(En ce moment, c'est un peu frustrant de l'avoir avec nous.)
(Peut-être qu'elle n'aurait pas dû venir. Chaque fois que j'essaie de l'aider, elle ne fait que se plaindre et s'en prendre à moi.)
(Tu pourrais t'ennuyer de vivre ici et rentrer chez toi.)
(Ou peut-être qu'il a raison et que je vis juste le fantasme d'Enoki.)
(Mais Enoki a été le seul bonheur que j'ai eu depuis des années.)
(Peut-être que quelque chose va changer... J'espère que nous-autres changerons tous les deux pour le mieux.)

OTHERS
(Probablemente no deba estar por aquí si no me han invitado...)
AUTRES (Je ne devrais probablement pas être ici si je n'ai pas été invité...)

MAPLE
(Es posible que no quiera        admitirlo, pero...)
(Es genial estar junto a ellos.  A veces olvido lo mucho que-)
(extraño estar acompañada.)
MAPLE
(Je ne voudrais peut-être pas l'admettre, mais...)
(C'est super d'être avec eux. Parfois, j'oublie à quel point ça me manque d'être avec eux.)

ENOKI
(A veces desearía ir atrás en el tiempo para hablar conmigo misma)
(NO ME CREERÍA si le contase todolo que pasó durante este año.)
(Y... no creo que mis padres     sepan que estoy aquí.)
(Me pregunto dónde creerán que   estoy ahora mismo.)
ENOKI
(Parfois j'aimerais pouvoir remonter le temps pour me parler)
(Tu ne me CROIREZ PAS si je te racontais tout ce qui s'est passé cette année.)
(Et... je ne pense pas que mes parents sachent que je suis ici.)
(Je me demande où ils pensent que je suis en ce moment.)

AARON
(De veras hace falta conseguir   un lugar para Maple.)
(No pensé que lo daría todo      para cumplir con su parte...)
(Con toda esa espeleología hemos conseguido cubrir los gastos.)
(Me sorprende que no pidiese un  nuevo lugar en el que quedarse.)
(Es posible que no quiera        quedarse sola.)
(Y no me apetece mucho tener que hacer otra casa.)
(Hablaré con ese tal Olivier y   veremos qué se puede hacer.)
(Parece un hombre de confianza.)
AARON
(Je avez vraiment besoin de trouver une place pour Maple.)
(Je ne pensais pas qu'il donnerait tout pour remplir sa part...)
(Avec toute cette spéléologie, nous-autres avons réussi à atteindre le seuil de rentabilité.)
(Je suis surpris qu'il n'ait pas demandé un nouveau logement.)
(Vous ne voudrez peut-être pas rester seul.)
(Et je ne veux pas vraiment avoir à faire une autre maison.)
(Je vais parler à cet Olivier et voir ce qui peut être fait.)
(Il semble être un homme confiant.)

OTHERS
(Sí, eso es una habitación.)
LES AUTRES
(Oui, c'est une chambre.)

OLIVIER
(Me gusta el sol que hace aquí.)
(Podría poner algunas plantas.)
Olivier
(J'aime le soleil ici.)
(Je pourrais mettre des plantes.)

ELEANOR
(Me recuerda mucho a la casa de  los padres de Vee.)
(Espero que sean personas en las que pueda confiar.)
ELEANOR
(Ça me rappelle beaucoup la maison des parents de Vee.)
(J'espère que ce sont des gens de confiance.)

DIANA
(Ok, me agradan estas personas.)
(Me hacen sentir ordenada.)
DIANA
(Ok, j'aime ces gens.)
(Ils me font me sentir propre.)

MAPLE
(Agradezco al de arriba que ese  chico nuevo sea cocinero.)
(Comer siempre lo mismo no sería tan pesado si otro cocinara.)
(Con suerte, puede que hasta     tenga sentido del humor.)
(Ugh, no sé qué diantres me pasa.¿Tengo ganas de conocerle?)
(Estaré perdiendo el tarro si me estoy volviendo sociable...)
MAPLE
(Je remercie celui ci qui dit que ce nouveau gars est un cuisinier.)
(Manger la même chose encore et encore ne serait pas si lourd si quelqu'un d'autre faisait la cuisine.)
(Espérons qu'il ait le sens de l'humour.)
(Ugh, je ne sais pas ce qui ne va pas chez moi. Est-ce que je veux le rencontrer?)
(Je vais perdre le pot si je deviens sociable...)

ENOKI
(Esta habitación no ha cambiado  en absoluto.)
(¿Y si moviese la cama hacia el  otro lado?)
(Hmm, sería más difícil ocultar  la ropa a los invitados.)
(Debería recoger esos... eh...   ...mejor lo hago luego.)
ENOKI
(Cette pièce n'a pas changé du tout.)
(Et si je déplaçais le lit de l'autre côté?)
(Hmm, il serait plus difficile de cacher des vêtements aux invités.)
(Je devrais récupérer ces... euh... ... mieux vaut le faire plus tard.)

AARON
(Ahí va la última oportunidad    de que Maple se fuese de aquí.)
(Mientras Enoki esté contenta conque Maple se quede en la casa.)
(Este dejará de ser mi hogar. No sé qué mosca le habrá picado.)
(Usa su orgullo para ocultar a lasanguijuela que realmente es.)
(Y Enoki empieza a darse cuenta  de lo molesto que estoy.)
(Mierda... Estoy empezando a     sonar como Maple.)
(¿Acaso son todos los hermanos   de esta manera?)
(Ojalá poder pedir consejo a     alguien, pero ni amigos tengo.)
AARON
(Voilà la dernière chance de Maple de sortir d'ici.)
(Tant que Enoki est content, Maple reste dans la maison.)
(Ce ne sera plus ma maison. Je ne sais pas quelle mouche l'a piqué.)
(Utilise sa fierté pour cacher à la sangsue qui il est vraiment.)
(Et Enoki commence à réaliser à quel point je suis contrarié.)
(Merde... Je commence à ressembler à Maple.)
(Est-ce que tous les frères sont ainsi?)
(J'aimerais pouvoir demander conseil à quelqu'un, mais je n'ai pas d'amis.)

OLIVIER
(Se acerca el cumpleaños de AaronUna planta sería un buen regalo.)
OLIVIER
(L'anniversaire d'Aaron approche. Une plante serait un beau cadeau.)


DIANA
(Me gusta el sol que hace aquí.)
(Podría poner algunas plantas.)
DIANA
(J'aime le soleil ici.)
(Je pourrais mettre des plantes.)

OTHERS
(No debería estar fisgoneando    por aquí.)
LES AUTRES
(Je ne devrais pas fouiller ici.)

MAPLE                            Oye, ¿Qué es ese libro?
AARON                            Oh, es mío.
AARON                            Ya sabes que no me va mucho la  ficción,
AARON                            Pero Enoki es un poco cabezota  a veces.
ENOKI                            ¿Has escuchado acerca de        Yellow?
ENOKI                            Es muy divertido, Aaron le está dando una oportunidad.
MAPLE                            ...¿Es un libro de dibujos?
MAPLE                            ¿Aún lees libros ilustrados?
ENOKI                            ¡Este tiene cigarrillos dentro!
ENOKI                            Eso significa que espara niños yadultos.
MAPLE                            Huh, ¿de verdad hacen           libros así?
MAPLE                            Hé, c'est quoi ce livre?
AARON                            Oh, c'est à moi.
AARON                            Tu sais que je n'aime pas beaucoup la fiction,
AARON                            Mais Enoki est parfois un peu têtu.
ENOKI                            Avais-tu entendu parler de Yellow?
ENOKI                            C'est tellement amusant, Aaron essaie.
MAPLE                            ...Est-ce un livre d'images?
MAPLE                            Lises-tu still des livres d'images?
ENOKI                            Celui-ci contient des cigarettes!
ENOKI                            Cela signifie que c'est pour les enfants et les adultes.
MAPLE                            Hein, est-ce qu'ils font vraiment des livres comme ça?

This has a choice : the “/” signifies a branching point
ENOKI                            Oh, oh Maple? You want juice?
MAPLE                            What kind of juice?
ENOKI                            It's a secret.
MAPLE                            I'm not drinking mystery liquid.
ENOKI                            ....
ENOKI                            Ok fine, it's orange juice / POISON
MAPLE                            You don't think I would have
MAPLE                            found that out?
ENOKI                            Maybe?
MAPLE                            No. Merci.
//
MAPLE						Coming from you? It might be.
ENOKI						Guess you gotta drink it to find out, huh?
MAPLE						Yeah, I’m not that thirsty.

(We're kind of low on orange     juice.)
(I'll probably need to head to   town and sell some produce.)
(Selling one fruit to get        another fruit, heh.)
(If only cucumber juice tasted   a little better.)

ENOKI                            EEEE! All my friends know
ENOKI                            Each other now!!
ENOKI                            We're like a proper group.
MAPLE                            Whoa, I haven't decided if-
MAPLE                            I'm staying, chill out.
SCOUT                            Anyone else showing up?
AARON                            I guess we'll wait and see.

MAPLE                            So, it looks like I've read 'em  all.
AARON                            We haven't gone to town in a     while.
MAPLE                            I wonder what's going on outside.
ENOKI                            If anything was bad, you know
ENOKI                            Scout woulda' said something.
ENOKI                            He's got that internet thing.
MAPLE                            I wonder if I can get new books  that way.
AARON                            That would sure be nice.

You see a bunch of books you've  never seen before.
None look particularly           interesting... for now.

MAPLE                            I think we need a VCR.
AARON                            You gonna buy one?
MAPLE                            Yes. And lots of tapes.
ENOKI                            Ooo, can you get the new Time Raider
ENOKI                            movie? I heard they made one!
MAPLE                            Just to spite you, I think I'll get
MAPLE                            everything I can find BUT that.																			
ENOKI                            Aw.. I was thinking that maybe
ENOKI                            y'know, since we all like it,
ENOKI                            ...have a kingdom movie night?
MAPLE                            Okay, MAYBE. MAYBE.


You smile, thinking about their  inferior kitchen.
Definitely gonna become regulars.

AARON                            I need to check on the others.

ENOKI'S GARDEN                   You touch it, I kill you

WOOD CHOPPING SPOT               Where wood is chopped

Hmmm... This seems like somethingfor Enoki.

Hmmm... This seems like somethingfor Aaron.
    
CAVE OF DANGEROUS BATS           Warning: Contains Bats

I think Maple is the only one whocan go in safely.
    
MAPLE                            Plants, huh?
MAPLE                            Isn't there a garden up top?
SCOUT                            You see, I, er-
SCOUT                            It's not really about the plants.
SCOUT                            I'm a dirt scientist.
MAPLE                            Dirt scientist?
SCOUT                            There's a scientist for, uh..
SCOUT                            Well, everything.
MAPLE                            Clearly.

ENOKI                            I think THAT plant is the one.
ENOKI                            That's my favorite.
SCOUT                            You want a cutting?
ENOKI                            What is it?
SCOUT                            I... I don't know, actually.
SCOUT                            I study dirt, not plants.
ENOKI                            Maybe it's a mystery fruit!
SCOUT                            I.. guess it could be.

AARON                            Any progress?
SCOUT                            Heck yeah!
SCOUT                            I've got something new.
AARON                            What's it called?
SCOUT                            I call it 'Scout-Out'.
SCOUT                            Guaranteed to get rid of weeds.
AARON                            Dude, that's amazing!
SCOUT                            Only issue is, well...
SCOUT                            It gets rid of the plants, too.
AARON                            Ah, bummer.

(Oh man, oh man oh man oh man..)
(I need to get this new formula  figured out fast.)
(Maybe promising the investors   magic dirt was a bad idea.)
(Maybe I can just hide down here and they won't find me.)
(Probably should take my name offmy hatch, first.)

MAPLE                            Same thing going on here?
SCOUT                            Yeah, yeah.
MAPLE                            They still haven't talk to you
MAPLE                            about your results?
SCOUT                            Nah.. But I'm still getting a
SCOUT                            paycheck every week.
MAPLE                            Hey, that's good.
SCOUT                            Oh yeah.

(Maple's been looking at these   plants every once in while..)
(At least she's got an opinion onthem.)
(I really, really need my boss tomessage me back about them.)
(I guess I shouldn't rock the    tree, the paycheck is solid.)
(I just want to make sure I'm    doing everything right.)

(Lots of unusual plants and dirt samples in jars.)
(You don't understand it... but  it's probably harmless.)

SCOUT                            Hey, uh.. Maple?
SCOUT                            Can I ask you something?
MAPLE                            Yeah, what's up?
SCOUT                            Do.. you.. er- like.. tennis?
MAPLE                            I love tennis. // Ew, tennis.
MAPLE                            Why do you ask?
SCOUT                            Oh, nothing, nothing.. I was..
MAPLE                            You want to play tennis?
SCOUT                            I mean, I've kinda always wanted
SCOUT                            to a bit, but I don't have
SCOUT                            anywhere to play, you know?
MAPLE                            Well, you get the field, and
MAPLE                            I might show you a thing or two.
SCOUT                            Aw, you mean it??
MAPLE                            Sure thing.
SCOUT                            Merci!
//
SCOUT                            Oh, nevermind, then.
MAPLE                            Whatever.


AARON                            Ok, so, hear me out.
AARON                            You've got that tool for making
AARON                            bunkers like this really easily
AARON                            right? So...
AARON                            Underground race track.
SCOUT                            Oh dude, that'd be sick!
SCOUT                            I'll definitely look into that.

(Well, it's time. They want my   samples.)
(Let's hope I don't get fired.)

(Lots of unusual plants and dirt samples in jars.)
(You don't understand it... but  it's probably harmless.)

MAPLE                            Hey look, more nerd stuff.
SCOUT                            Excusez-moi, mademoiselle!
SCOUT                            That's Time Raiders!
MAPLE                            Time... Raiders?
SCOUT                            Yeah! The adventures of
SCOUT                            Jahn-Jahn Gazebo and his
SCOUT                            sidekicks, Nexus and Ninjette!
MAPLE                            Everything about that sounds..
MAPLE                            You ever have a girlfriend?
SCOUT                            No, girls thought I was a nerd.
MAPLE                            Girls still do, dude.

ENOKI                            Ooh, is this Time Raiders??
SCOUT                            You know Time Raiders??.
ENOKI                            'I've got it, Jahn-Jahn!'
SCOUT                            Finally, someone else!
ENOKI                            Yeah, Aaron introduced me.
ENOKI                            I like the artwork.
ENOKI                            Can I borrow this after you?
SCOUT                            Sure thing! I'm almost done.

AARON                            Yo, Time Raiders?
SCOUT                            Heck yeah!
AARON                            Nice! You check out the latest?
SCOUT                            Oh no, not yet.
SCOUT                            Something you'll learn about, er-
SCOUT                            'Island Life',
SCOUT                            Getting new things is hard.
SCOUT                            I could just use my computer, but
SCOUT                            That kills the experience.
AARON                            Definitely, definitely.


(I've gotta finish this one so   I can get it to Enoki.)
(But that formula I promise...   I swear, I'm so close.)
(Maybe just a few more           all-nighters.)
(A few more and I'll finally haveit.)

SCOUT                            Hey, you know, you like to read
SCOUT                            a lot, right?
MAPLE                            Sure thing.
SCOUT                            Do you think that maybe I could
SCOUT                            borrow some of your books?
MAPLE                            You wouldn't like them.
SCOUT                            I'm sure I could try.
MAPLE                            You like romance? // You like mushy period pieces?
MAPLE                            Hot and steamy romance?
SCOUT                            I... do you have anything else?
MAPLE                            No, that's what I like.
MAPLE                            What, it make you uncomfortable?
SCOUT                            ..Maybe a bit.
MAPLE                            Yeah, stick to your comic books.
//
SCOUT                            I mean, I can learn to like them.
MAPLE						Give me a break.

SCOUT                            Hey, Enoki?
ENOKI                            Yuh-huh?
SCOUT                            Can we talk about Maple?
ENOKI                            Oooh, what about her?
ENOKI                            You LIKE her, don't you?
SCOUT                            What's not to like?
ENOKI                            We all already know, hehe.
SCOUT                            Aw crap, it's obvious.
ENOKI                            She's hard to get.
ENOKI                            I tried to set her up once.
SCOUT                            You did?
ENOKI                            They even dated for a bit.
ENOKI                            He just got on her nerves.
ENOKI                            You gotta be perfect for her.
SCOUT                            And I'm not.
ENOKI                            I don't know what perfect is.
SCOUT                            Well, I can dream I guess.
ENOKI                            But hey, don't change yourself.
ENOKI                            Just be the best 'you'.
SCOUT                            I guess you're right.
ENOKI                            The right girl'll come in time.
SCOUT                            Right. Merci, Enoki.
ENOKI                            De rien!

SCOUT                            Hey, bro, so, how'd you, er..
SCOUT                            How'd you first ask Enoki out?
AARON                            I just invited her to coffee.
SCOUT                            Coffee, coffee, right..
SCOUT                            We don't uh, hmm.. No coffee..
AARON                            You want to ask Maple out?
SCOUT                            Well, I.. Yeah, I do.
AARON                            I'd tell you to give up, but at
AARON                            the same time, you never know.
AARON                            No one's good enough for her.
SCOUT                            I figured it wasn't worth it.
AARON                            Absolutely no pleasing her.
AARON                            Trust me, I know.
SCOUT                            What do you mean?
AARON                            Her type is those losers who
AARON                            they're way cooler than they
AARON                            are. Now, I'll give her some
AARON                            credit, though. She puts up
AARON                            with a lot of the other kind
AARON                            of loser, too. Just...
AARON                            Work on yourself. Maybe try
AARON                            to be a bit more confident and
AARON                            socially-aware, right?
SCOUT                            Right. That's a good start.
AARON                            Good luck, man.
SCOUT                            Merci.

(Maybe if I can just get Maple toread a few copies,)
(We'll finally have something in common with her.)
(In my dreams.)

GUY                              You like Time Raiders?
SCOUT                            Yeah, a bit.
GUY                              How often you get new ones?
SCOUT                            Diana ships in new ones weekly.
GUY                              Ah okay, I didn't wanna move
GUY                              here and have to give it up.
SCOUT                            There is a bit of a waiting
SCOUT                            list, though. You gotta go
SCOUT                            after Enoki, she likes em.
GUY                              Nah, I'll just take em first.
SCOUT                            Look, you take that up with her.
GUY                              Will do.

(Last month's comic books remain lying on the floor.)
(Slowly collecting dust.)

SCOUT                            Hey, please be careful about-
SCOUT                            my computer, it's expensive.
MAPLE                            I'm not gonna touch it.
MAPLE                            Although, now I want to..
SCOUT                            Wait!! Please-
MAPLE                            Dude, I'm not gonna touch it!
MAPLE                            You nerds and your toys..

ENOKI                            Hey Scout, you got a website?
SCOUT                            Yeah! It's not very good though.
ENOKI                            May I see it?
SCOUT                            Not right now, it's... not done.
ENOKI                            Ah, okay.
ENOKI                            I wanna make a website.
ENOKI                            It looks like a lot of fun.
SCOUT                            It's definitely fun.

AARON                            You hear about the millenium bug?
SCOUT                            Well of course.
AARON                            Were you okay?
SCOUT                            Yeah, I was fine.
SCOUT                            There was a weird bug in
SCOUT                            one program.
SCOUT                            I had a shopping list program,
SCOUT                            It added tons of shoeshine to my
SCOUT                            my shopping list, which is now
SCOUT                            due on March 5th, 192000.
AARON                            That's a little while to wait.
SCOUT                            A glitchy date? I understand.
SCOUT                            Extra items? That elludes me.
SCOUT                            Bugs are just the weirdest thing.

(I've graduated top of my class  with a 3.99 GPA.)
(I'm a real scientist, living    off a corporate grant.)
(I have a state of the art, whiz bang Castor 5000 computer.)
(And I can't use it, because I   forgot my password.)
(No wonder I can't sleep at      night.)

(This looks really expensive...)
(I probably shouldn't touch.)

(This green formula's been makingall the plants grow real big.)
(I wonder what would happen if   I had some...)
(Maybe I'll get super plant      powers...)
(Or maybe I'll just die.)
(Those plant powers better be    worth the risk.)

SCOUT                            Careful!!
SCOUT                            Some of this stuff is
SCOUT                            SUPER SUPER toxic!


SCOUT                            Bonjour! Are you Olivier?
OLIVIER                          Oui! And you're Scout?
SCOUT                            That I am! Welcome!
OLIVIER                          This whole place was amazing!
SCOUT                            I tried to be honest in the ad.
OLIVIER                          So, are you a scientist?
SCOUT                            You could say that, yeah.
SCOUT                            I do a little of everything.
OLIVIER                          And you live underground?
SCOUT                            I've got this machine that can
SCOUT                            Drill bunkers really easy.
SCOUT                            I could keep drilling if I
SCOUT                            really wanted to, you know.
OLIVIER                          Awesome!! Hey, you coming to
OLIVIER                          the Tremblay's for dinner?
SCOUT                            Of course!
OLIVIER                          Alright, I'll see you then!

ELEANOR                          Bonjour, monsieur!
SCOUT                            Bonjour! Are you Eleanor?
ELEANOR                          Oui! It's nice to meet you.
ELEANOR                          This whole place was amazing!
SCOUT                            I tried to be honest in the ad.
ELEANOR                          Are you a wizard?
SCOUT                            You could say that, yeah.
SCOUT                            I do a little of everything.
ELEANOR                          And you live underground?
SCOUT                            I've got this machine that can
SCOUT                            Drill bunkers really easy.
SCOUT                            I could keep drilling if I
SCOUT                            really wanted to, you know.
ELEANOR                          That's so fascinating!
SCOUT                            Aw, merci!
ELEANOR                          Tonight, will I see you at dinner?
SCOUT                            Of course!
ELEANOR                          Wonderful!

DIANA                            Bonjour! Hey, are you Scout?
SCOUT                            Bonjour! Are you Diana?
DIANA                            Oui! Nice to finally meet 'ya!
DIANA                            Man, this place is SICK!
SCOUT                            I tried to be honest in the ad.
DIANA                            Are you a scientist or something?
SCOUT                            You could say that, yeah.
SCOUT                            I do a little of everything.
DIANA                            And you live underground?
SCOUT                            I've got this machine that can
SCOUT                            Drill bunkers really easy.
SCOUT                            I could keep drilling if I
SCOUT                            really wanted to, you know.
DIANA                            Aw, that's so cool!
SCOUT                            Merci!
DIANA                            You coming to dinner?
SCOUT                            Of course!
DIANA                            Sweet!

(I wish I could make something   that would make me happy.)
(All that school and everything, but here I am, and...)
(I dunno. I move on from one     thing to the next thing,)
(I can't go anywhere without     immediately wanting to jump.)
(I just wanna be happy where I amfor once.)

Note: this is partially repeated, but not completely
SCOUT                            Careful!!
SCOUT                            Some of this stuff is
SCOUT                            SUPER SUPER toxic!
SCOUT                            Oh, well you already knew that.
SCOUT                            At least I hope so.

SCOUT                            Bonjour! You're Guy, right?
GUY                              Oui. So you're Scout?
SCOUT                            Bienvenu! You like your cabin?
GUY                              You weren't kidding about the
GUY                              kitchen, huh?
SCOUT                            Not a bit!
GUY                              There don't seem to be too many
GUY                              people here, and you know that
GUY                              I ain't gonna be making a ton of
GUY                              food without customers.
GUY                              How soon it is gonna be before we
GUY                              get a ton of new people here?
SCOUT                            Oh, it shouldn't be too long.
GUY                              And I can hold you to that?
SCOUT                            Sans doute.
GUY                              Tres bien alors.

ENOKI                            Salut? Scout, you down here?    
SCOUT                            Yeah! We're here! Where's        Aaron?
ENOKI                            He's out trying to check on      the others.
SCOUT                            Thank goodness. Hey, Maple-      are you feeling alright? You    
SCOUT                            look really tired.
MAPLE                            You shut up about me being       tired, I've had ENOUGH of that  
MAPLE                            this morning.
SCOUT                            Oh- Okay, sure.
SCOUT                            Hey Enoki, what's it look        like up there?
ENOKI                            Fine, it's just... there's this  weird, loud noise.
ENOKI                            Aaron got spooked and wanted us  to be safe.
SCOUT                            I trust his intuition.
    
AARON                            What the heck is going           on outside?
SCOUT                            It's Rufus. I think he ate       something weird.
ENOKI                            Hehe, I get like that after      some of Guy's cooking, too.     
SCOUT                            No, I'm being serious. It has to do with my research.
AARON                            Oh, so we finally get to know    what the mysterious bunker      
AARON                            scientist has been doing for     the past few months?
SCOUT                            I'm a dirt scientist, but I'm    also something else...
SCOUT                            I'm a plant scientist.
ENOKI                            Say it ain't so!
OLIVIER                          And you didn't tell me?
SCOUT                            No, it was confidential.
SCOUT                            See, there's this... plant. It   grows natively to these
SCOUT                            islands, and many people         believe it to be magic. It      
SCOUT                            makes you see things.
ENOKI                            Like mushrooms?
SCOUT                            Mushrooms make everyone see      different things. This flower   
SCOUT                            makes everyone see the SAME      thing. That's why we're
SCOUT                            studying it. It's not just a     trip, there's something going   
SCOUT                            on.
SCOUT                            Everyone who takes one acts      differently, but it's not       
SCOUT                            because of a chemical            imbalance. It's as if what they 
SCOUT                            see is so troubling, so          life-shattering, that they're   
SCOUT                            different people on the other    end.
ELEANOR                          What do they see, then?
SCOUT                            Nobody knows. They never tell    anyone anything.
SCOUT                            Everyone who takes it gets a     small blue ring around their    
SCOUT                            eyes. They don't seem to last    forever, but it's how you can   
SCOUT                            tell. I was looking at that      footage of Rufus, and sure      
SCOUT                            enough... blue ring.
AARON                            And so he's decided to become    a supervillain or something?    
SCOUT                            I don't know. Rufus isn't        very.. big, you know? So maybe- 

SCOUT                            Uhh.... I think something's at   the door.
AARON                            I've got my ax.
SCOUT                            Hey, I tell you guys what.       You know that bunker maker that 
SCOUT                            I have?
AARON                            Yeah...?
SCOUT                            I'll tell y'all what. Why        don't we bunker our way away    
SCOUT                            from the island? I was already   planning on making a tunnel to  
SCOUT                            shore.
SCOUT                            (I was hoping to save that one   for the Scout Expo, but, uh..)
SCOUT                            (I guess I don't really have an  option now do I.)
ELEANOR                          Is that safe?

SCOUT                            Actually let's just go.
ENOKI                            Allons-y?

You stare at the art.
And as such....
So the art stares unto you.
Art is weird.

- MORE HOUSES THIS WAY -

MAPLE                            Probably should go to Scout's.
ENOKI                            Oh,hey Maple, ¿quieres zumo?
MAPLE                            ¿Qué tipo de zumo?
ENOKI                            Eso es un secreto.
MAPLE                            No voy beber líquidos extraños.
ENOKI                            ....
ENOKI                            Venga va, es zumo de naranja / VENENO
MAPLE                            ¿Y no crees que me habría dado
MAPLE                            cuenta en cuanto lo probase?
ENOKI                            ¿Quizás?
MAPLE                            Paso. Merci.
//
MAPLE						Viniendo de ti, me lo creería.
ENOKI						Podrías probarlo y descubrirlo.
MAPLE						No es que tenga tanta sed.
ENOKI                            Oh, hey Maple, tu veux du jus?
MAPLE                            Quel type de jus?
ENOKI                            C'est un secret.
MAPLE                            Je ne boirai pas de liquides étranges.
ENOKI                            ....
ENOKI                            Allez, c'est du jus d'orange / POISON
MAPLE                            Et tu ne pensez pas que je l'aurais su dès que je l'ai essayé?
ENOKI                            Peut-être?
MAPLE                            Merci.
//
MAPLE                            Venant de toi, je le croirais.
ENOKI                            Tu peux l'essayer et le découvrir.
MAPLE                            Ce n'est pas que j'ai si soif.

(Nos queda poco zumo de naranja.)
(Probablemente tenga que ir al   pueblo a vender productos.)
(Vender una fruta para comprar   otra, heh.)
(Si al menos el zumo de tomate   tuviera mejor sabor...)
(Il nous-autres reste peu de jus d'orange.)
(Vous devez probablement aller en ville pour vendre des produits.)
(Vendre un fruit pour en acheter un autre, hein.)
(Si seulement le jus de tomate avait meilleur goût...)

ENOKI                            ¡EEEE! ¡Ahora todos mis amigos
ENOKI                            se conocen entre ellos!
ENOKI                            ¡Ahora sí que somos un grupo!
MAPLE                            Wow, aún no he decidido si-
MAPLE                            Si me quedo aquí, cálmate.
SCOUT                            ¿Va a venir alguien más?
AARON                            Tendremos que esperar y ver.
ENOKI                            EEEE! Maintenant tous mes amis se connaissent!
ENOKI                            Maintenant nous-autres sommes vraiment un groupe!
MAPLE                            Wow, je n'ai pas encore décidé si-
MAPLE                            Si je reste ici, calme-toi.
SCOUT                            Est-ce que quelqu'un d'autre vient?
AARON                            Nous devons juste attendre et voir.

MAPLE                            Creo que ya los leí todos.
AARON                            Hace tiempo que no vamos         al pueblo.
MAPLE                            Me pregunto qué estará pasando   fuera de aquí.
ENOKI                            Si algo malo hubiese ocurrido lo sabríamos.
ENOKI                            Scout habría dicho algo.
ENOKI                            Siempre está metido en internet.
MAPLE                            Podría pedirle que me compre     libros por internet.
AARON                            Esa sería una buena idea.
MAPLE                            Je pense que je les ai tous lus.
AARON                            Ça fait un moment que nous-autres ne sommes pas allés en ville.
MAPLE                            Je me demande ce qui se passe là-bas.
ENOKI                            Si quelque chose de grave s'était produit, nous-autres le saurions.
ENOKI                            Scout aurait dit quelque chose.
ENOKI                            est toujours sur Internet.
MAPLE                            Je pourrais te demander de m'acheter des livres en ligne.
AARON                            Ce serait une bonne idée.

Ves un montón de libros que      nunca antes habías visto.
Aunque ninguno de ellos parece   particularmente interesante...   Por ahora.
Vous voyez un tas de livres que vous n'avez jamais vus auparavant.
Bien qu'aucun d'entre eux ne semble particulièrement intéressant... Pour l'instant.

MAPLE                            Creo que necesitamos un VHS.
AARON                            ¿Vas a comprar uno?
MAPLE                            Sí. Y un montón de cintas.
ENOKI                            Oooh, ¿Puedes conseguir la última 
ENOKI                            peli de Time Raider? ¡Escuché que hicieron una nueva!
MAPLE                            Sólo por fastidiarte, compraré
MAPLE                            todas las que vea EXCEPTO esa.
ENOKI                            Aw... Estaba pensando que quizá,
ENOKI                            si a todos nos agrada la idea.
ENOKI                            ... ¿Tener una noche de pelis?
MAPLE                            Está bien, PUEDE que hagamos eso.
MAPLE                            Je pense qu'il nous-autres faut une VHS.
AARON                            Allez-tu en acheter un?
MAPLE                            Oui, et beaucoup de groupes.
ENOKI                            Oooh, peux-tu obtenir le dernier film Time Raider? J'ai entendu dire qu'ils en avaient fait un nouveau!
MAPLE                            Par dépit, j'achèterai tous ceux que je vois SAUF celui-là.
ENOKI                            Aw... Je pensais peut-être que nous-autres aimions tous cette idée.
ENOKI                            ... Une soirée cinéma?
MAPLE                            D'accord, on PEUT le faire.

Sonríes, pensando que no saben   cocinar demasiado bien.
Definitivamente se convertirán   en clientes habituales.
Tu souris en pensant qu'ils ne savent pas très bien cuisiner.
Ils deviendront certainement des clients réguliers.

AARON                            Necesito ver cómo van los demás.
AARON                            J'ai besoin de voir comment vont les autres.

ENOKI'S GARDEN                   Si tocas algo, acabaré contigo.
LE JARDIN D'ENOKI                Si tu touches quoi que ce soit, je te tue.

WOOD CHOPPING SPOT               Donde se corta la leña.
POINT DE COUPE DU BOIS           L'endroit où le bois est coupé.

Hmmm... Esta parece una tarea    indicada para Enoki.
Hmmm... Cela semble être une tâche appropriée pour Enoki.

Hmmm... Esta parece una tarea    indicada para Aaron.
Hmmm... Cela semble être une mission appropriée pour Aaron.
    
CUEVA DE MURCIÉLAGOS PELIGROSOS  Advertencia: hay murciélagos.

Creo que Maple es la única que   puede entrar con seguridad.

GROTTE DES CHAUVES-SOURIS DANGEREUSES Attention : il y a des chauves-souris.

Je pense que Maple est le seul à pouvoir entrer en toute sécurité.
    
MAPLE                            ¿Plantas, eh?
MAPLE                            ¿No hay.. ya un jardín?
SCOUT                            Verás, yo, ehm-
SCOUT                            Realmente no es por las plantas
SCOUT                            Soy un investigador de tierra.
MAPLE                            ¿Investigador de tierra?
SCOUT                            Hay un investigador para cada...
SCOUT                            Bueno, para todo, realmente.
MAPLE                            Ya, claro.
MAPLE                            Des plantes, hein?
MAPLE                            N'y a-t-il pas un jardin?
SCOUT                            Tu vois, je, euh-
SCOUT                            Il ne s'agit vraiment pas de plantes
SCOUT                            Je suis enquêteur au sol.
MAPLE                            Enquêteur au sol?
SCOUT                            Il y a un investigateur pour chaque...
SCOUT                            Eh bien, pour tout, vraiment.
MAPLE                            Oui, bien sûr.

ENOKI                            CREO que esa es la planta.
ENOKI                            Esta es mi favorita.
SCOUT                            ¿Quieres que la corte?
ENOKI                            ¿Qué es eso?
SCOUT                            La verdad es que no lo sé...
SCOUT                            Estudio la tierra, no plantas.
ENOKI                            ¡Podría ser un fruto misterioso!
SCOUT                            Pues... Podría ser.
ENOKI                            JE PENSE que c'est la plante.
ENOKI                            C'est mon préféré.
SCOUT                            Voulez-vous que je coupe?
ENOKI                            Qu'est-ce que c'est?
SCOUT                            Je ne sais vraiment pas...
SCOUT                            J'étudie la terre, pas les plantes.
ENOKI                            Ce pourrait être un fruit mystérieux!
SCOUT                            Et bien... C'est possible.

AARON                            ¿Has hecho progresos?
SCOUT                            ¡Y tanto que sí!
SCOUT                            He conseguido algo nuevo.
AARON                            ¿Cómo se llama?
SCOUT                            Lo bauticé como 'Scout-Out'.
SCOUT                            Puede quitar las malas hierbas.
AARON                            ¡Tío, eso es una pasada!
SCOUT                            El único problema es que...
SCOUT                            Se cargará el resto de plantas.
AARON                            Qué bajón, tan útil no es...
AARON                            Avez-vous fait des progrès?
SCOUT                            Et donc oui!
SCOUT                            J'ai quelque chose de nouveau.
AARON                            Comment s'appelle-t-il?
SCOUT                            Je l'ai baptisé 'Scout-Out'.
SCOUT                            Vous pouvez enlever les mauvaises herbes.
AARON                            Mec, c'est tellement cool!
SCOUT                            Le seul problème est que...
SCOUT                            Toutes les autres plantes seront facturées.
AARON                            Quel déprimant, si utile n'est pas...

(¡Oh tío, oh tío, oh tío...!)
(Necesito conseguir esa fórmula  lo más rápido posible.)
(Prometer tierra mágica a los    inversores no fue buena idea.)
(Si me escondo aquí abajo puede  que no lleguen a encontrarme.)
(Aunque primero debería quitar   mi nombre de la escotilla...)
(Oh mec, oh mec, oh mec...!)
(Je dois obtenir cette formule aussi vite que possible.)
(Promettre des terres magiques aux investisseurs n'était pas une bonne idée.)
(Si je me cache ici, ils pourraient ne pas me trouver.)
(Bien que je devrais d'abord retirer mon nom de la trappe ...)

MAPLE                            ¿Sigue ocurriendo lo mismo?
SCOUT                            La verdad es que sí.
MAPLE                            ¿Aún no han hablado contigo 
MAPLE                            sobre los resultados?
SCOUT                            Aún no, pero sigo recibiendo
SCOUT                            mi sueldo cada semana.
MAPLE                            Hey, eso es bueno.
SCOUT                            Pues sí.
MAPLE                            Est-ce que la même chose se produit encore?
SCOUT                            La vérité est que oui.
MAPLE                            Ne t'ont-ils pas encore parlé
MAPLE                            sur les résultats?
SCOUT                            Pas encore, mais je reçois toujours
SCOUT                            mon salaire chaque semaine.
MAPLE                            Hé, c'est bien.
SCOUT                            Oui.

(Maple ha estado mirando las     plantas de vez en cuando...)
(Al menos me dijo lo que opina   de ellas con sinceridad.)
(Necesito urgentemente que mi    jefe responda a mis mensajes.)
(Recibo un buen sueldo y no      debería jugármela demasiado.)
(Tan sólo he de asegurarme de    seguir los pasos correctos.)
(Maple regarde les plantes de temps en temps...)
(Au moins, il m'a dit ce qu'il pensait honnêtement d'eux.)
(J'ai besoin de toute urgence que mon patron réponde à mes messages.)
(Je reçois un bon salaire et je ne devrais pas trop le risquer.)
(Je dois juste m'assurer de suivre les étapes correctes.)

(Ejemplares de tierra y plantas  inusuales metidas en frascos.)
(Aunque todo parece inofensivo,  sigues sin entender nada.)
(Spécimens moulus et plantes insolites mis en bocaux.)
(Bien que tout semble inoffensif, vous ne comprenez toujours rien.)

SCOUT                            Hey, uh... ¿Maple?
SCOUT                            ¿Puedo hacerte una pregunta?
MAPLE                            Claro, ¿qué ocurre?
SCOUT                            A... ti... ¿T-te gusta el tenis?
MAPLE                            Amo el tenis  // Es muy aburrido
MAPLE                            ¿A qué viene esa pregunta?
SCOUT                            Oh, nada, nada... Sólo me...
MAPLE                            ¿Quieres jugar conmigo al tenis?
SCOUT                            Siempre quise jugar al tenis,
SCOUT                            pero realmente no tengo a
SCOUT                            nadie con quién jugar, ¿sabes?
MAPLE                            En otro momento podríamos ir al
MAPLE                            campo de tenis y jugar un rato.
SCOUT                            ¿L-lo estás diciendo en serio?
MAPLE                            Claro.
SCOUT                            ¡Merci!
//
SCOUT                            Oh, no pasa nada entonces.
MAPLE                            Está bien.
SCOUT                            Hé, euh... Maple?
SCOUT                            Puis-je vous poser une question?
MAPLE                            Bien sûr, quoi de neuf?
SCOUT                            V... vous... D-aimez-vous le tennis?
MAPLE                            J'aime le tennis // C'est tellement ennuyeux
MAPLE                            Qu'est-ce que c'est que cette question?
SCOUT                            Oh, rien, rien... J'ai juste...
MAPLE                            Tu veux jouer au tennis avec moi?
SCOUT                            J'ai toujours voulu jouer au tennis, mais je n'ai personne avec qui jouer, tu connais?
MAPLE                            Une autre fois, nous-autres pourrions aller au court de tennis et jouer à un match.
SCOUT                            T'es sérieux?
MAPLE                            Clair.
SCOUT                            Merci!
//
SCOUT Oh, ça va alors.
MAPLE D'accord.

AARON                            Vale, escúchame un momento.
AARON                            Tienes esa herramienta para 
AARON                            hacer búnkers como este con 
AARON                            facilidad, ¿no? Podemos hacer-
AARON                            ¡Una carrera subterránea!
SCOUT                            Oh tío, ¡es una gran idea!
SCOUT                            ¡Me encantaría intentarlo!
AARON                            D'accord, écoutez-moi une minute.
AARON                            Vous avez cet outil pour
AARON                            fabrique des bunkers comme celui-ci avec
AARON                            facile, non? Nous pouvons faire-
AARON                            Une course clandestine!
SCOUT                            Oh mec, c'est une super idée!
SCOUT                            J'adorerais l'essayer!

(Bueno, llegó el momento. Quierenque le dé mis muestras.)
(Espero que no me despidan.)
(Well, le moment est venu. Il veut que je lui donne mes échantillons.)
(J'espère que je ne me ferai pas virer.)

(Ejemplares de tierra y plantas  inusuales metidas en frascos.)
(Aunque todo parece inofensivo,  sigues sin entender nada.)
(Spécimens moulus et plantes insolites mis en bocaux.)
(Bien que tout semble inoffensif, vous ne comprenez toujours rien.)

MAPLE                            Hey mira, más frikadas.
SCOUT                            ¡Excusez-moi, mademoiselle!
SCOUT                            ¡Son los Time Raiders!
MAPLE                            ¿Time... Raiders?
SCOUT                            ¡Sí! ¡Las aventuras de
SCOUT                            Jahn-Jahn Gazebo y sus
SCOUT                            compinches, Nexus y Ninjette!
MAPLE                            Todo eso suena demasiado...
MAPLE                            ¿Has tenido novia alguna vez?
SCOUT                            No, las chicas me decían friki.
MAPLE                            Las chicas lo siguen diciendo.
MAPLE                            Hé, regarde, plus de monstres.
SCOUT                            Excusez-moi, mademoiselle!
SCOUT                            C'est les Time Raiders!
MAPLE                            Time... Raiders?
SCOUT                            Oui! Les aventures de
SCOUT                            Jahn-Jahn Gazebo et ses copains, Nexus et Ninjette!
MAPLE                            Ça sonne aussi...
MAPLE                            Avez-vous déjà eu une petite amie?
SCOUT                            Non, les filles m'ont traité de monstre.
MAPLE                            Les filles n'arrêtent pas de le dire.

ENOKI                            ¡Oh! ¿Son los Time Raiders?
SCOUT                            ¿Conoces a los Time Raiders?
ENOKI                            '¡Lo conseguí, Jahn-Jahn!'
SCOUT                            ¡Al fin alguien más!
ENOKI                            Sí, Aaron me lo enseñó.
ENOKI                            Me gusta el estilo de dibujo.
ENOKI                            ¿Me lo dejarías prestado?
SCOUT                            ¡Claro! Casi lo he terminado.
ENOKI                            Ah! Sont-ils les Time Raiders?
SCOUT                            Connaissez-vous les Time Raiders?
ENOKI                            'J'ai compris, Jahn-Jahn!'
SCOUT                            Enfin quelqu'un d'autre!
ENOKI                            Oui, Aaron m'a appris.
ENOKI                            J'aime le style de dessin.
ENOKI                            Voulez-vous me le prêter?
SCOUT                            Bien sûr! J'ai presque fini.

AARON                            Tío, ¿no son los Time Raiders?
SCOUT                            ¡Vaya que sí!
AARON                            ¡Qué guapo! ¿La llevas al día?
SCOUT                            Qué va, todavía no.
SCOUT                            Algo que aprenderás en tu nueva
SCOUT                            'Vida Isleña', es que conseguir
SCOUT                            cosas nuevas puede ser difícil.
SCOUT                            Podría seguir leyendo en el PC,
SCOUT                            pero no es lo mismo para nada.
AARON                            Estoy totalmente de acuerdo.
AARON                            Mec, c'est pas les Time Raiders?
SCOUT                            Ah oui!
AARON                            Qu'il est beau! Le tenez-vous à jour?
SCOUT                            Quoi de neuf, pas encore.
SCOUT                            Quelque chose que vous apprendrez dans votre nouveau
SCOUT                            'Island Life', c'est qu'il peut être difficile d'obtenir de nouvelles choses.
SCOUT                            Je pourrais continuer à lire sur le PC, mais ce n'est pas du tout pareil.
AARON                            Je suis tout à fait d'accord.

(Debo terminar con esto para así dárselo a Enoki.)
(Pero la fórmula que prometí...  Estoy muy cerca de lograrla.)
(Tal vez pueda conseguirlo tras  unas noches sin dormir.)
(Un poco más y al fin podré      tenerlo listo.)
(Je dois le finir pour pouvoir le donner à Enoki.)
(Mais la formule que j'ai promise... Je suis très proche de l'atteindre.)
(Peut-être que je peux l'obtenir après quelques nuits blanches.)
(Encore un peu et je peux enfin l'avoir prêt.)

SCOUT                            Oye, a ti te gusta mucho leer
SCOUT                            libros, ¿no es así?
MAPLE                            A la vista está.
SCOUT                            ¿Crees que podrías prestarme
SCOUT                            algunos de tus libros?
MAPLE                            No te gustarían.
SCOUT                            Al menos quisiera intentarlo.
MAPLE                            ¿Te gustan los románticos?
MAPLE                            ¿Las relaciones complicadas?
SCOUT                            Y... ¿No tienes de otro tipo?
MAPLE                            No, eso es lo que me gusta.
MAPLE                            ¿Acaso te hace sentir incómodo?
SCOUT                            ... Quizá un poco.
MAPLE                            Mejor sigue leyendo tus cómics.
SCOUT                            Hé, tu aimes vraiment lire des livres, n'est-ce pas?
MAPLE                            En vue ça l'est.
SCOUT                            Pensez-vous que vous pourriez me prêter
SCOUT                            certains de vos livres?
MAPLE                            Vous ne l'aimeriez pas.
SCOUT                            Au moins, j'aimerais essayer.
MAPLE                            Aimez-vous les romantiques?
MAPLE                            Des relations compliquées?
SCOUT                            Et... Vous n'en avez pas d'autres?
MAPLE                            Non, c'est ce que j'aime.
MAPLE                            Cela vous met-il mal à l'aise?
SCOUT                            ... Peut-être un peu.
MAPLE                            Mieux vaut continuer à lire vos bandes dessinées.

SCOUT                            Oye, ¿Enoki?
ENOKI                            ¿Sí?
SCOUT                            ¿Podemos hablar de Maple?
ENOKI                            Oooh, ¿qué ocurre con ella?
ENOKI                            TE GUSTA Maple, ¿no es así?
SCOUT                            ¿Qué dices de gustar?
ENOKI                            Ya nos lo sabemos todos, jeje.
SCOUT                            Mierda, ¿tan obvio es?.
ENOKI                            Pero ella es complicada.
ENOKI                            Una vez le presenté a un chico.
SCOUT                            ¿Le presentaste a un chico?
ENOKI                            Y salieron durante un tiempo.
ENOKI                            Aunque se hartó y la dejó.
ENOKI                            Debes ser perfecto para ella.
SCOUT                            Y yo no lo soy.
ENOKI                            No sé quién podría serlo.
SCOUT                            Bueno, un hombre puede soñar.
ENOKI                            Aunque no tienes que cambiar.
ENOKI                            Sólo debes ser 'tú mismo'.
SCOUT                            Supongo que tienes razón.
ENOKI                            Darás con la chica adecuada.
SCOUT                            Está bien. Merci, Enoki.
ENOKI                            ¡De rien!
SCOUT                            Hé, Enoki?
ENOKI                            Oui?
SCOUT                            Peut-on parler de Maple?
ENOKI                            Oooh, qu'est-ce qui ne va pas avec elle?
ENOKI                            VOUS AIMEZ le Maple, n'est-ce pas?
SCOUT                            Que diriez-vous de l'aimer?
ENOKI                            Nous le savons tous déjà, hehe.
SCOUT                            Merde, c'est si évident?
ENOKI                            Mais elle est compliquée.
ENOKI                            Je l'ai présentée une fois à un garçon.
SCOUT                            L'avez-vous présenté à un garçon?
ENOKI                            Et ils sont sortis ensemble pendant un moment.
ENOKI                            Bien qu'il en ait eu marre et l'a quittée.
ENOKI                            Tu dois être parfait pour elle.
SCOUT                            Et je ne le suis pas.
ENOKI                            Je ne sais pas qui cela pourrait être.
SCOUT                            Eh bien, un homme peut rêver.
ENOKI                            Vous n'avez pas à changer cependant.
ENOKI                            Vous n'avez qu'à être " vous-même ".
SCOUT                            Je suppose que tu as raison.
ENOKI                            Vous trouverez la bonne fille.
SCOUT                            D'accord. Merci, Enoki.
ENOKI                            De rien!

SCOUT                            Ehm... ¿Cómo tuviste una cita
SCOUT                            con Enoki por primera vez?
AARON                            Sólo le invité a tomar café.
SCOUT                            Café, café... Vale.
SCOUT                            No tenemos, hmm... Café...
AARON                            ¿Quieres salir con Maple?
SCOUT                            Bueno, yo... Sí, me gustaría.
AARON                            Podrías intentarlo, pero es
AARON                            complicado. Ningún chico es
AARON                            lo bastante bueno para ella.
SCOUT                            Quizá sea inútil intentarlo.
AARON                            Es imposible complacerla.
AARON                            Créeme, la conozco bien.
SCOUT                            ¿A qué te refieres?
AARON                            Su tipo son los perdedores
AARON                            que se creen mejores de lo 
AARON                            que son. Aunque a decir 
AARON                            verdad. También le he visto
AARON                            salir con otro tipo de
AARON                            pringados. Quizá sólo tengas
AARON                            que esforzarte un poco en 
AARON                            tener algo más de confianza
AARON                            en ti mismo, ¿sabes?
SCOUT                            Bueno, eso un buen comienzo.
AARON                            Buena suerte con ella, tío.
SCOUT                            Merci.
SCOUT                            Ehm... comment es-tu sorti avec
SCOUT                            Enoki pour la première fois?
AARON                            Je viens de lui acheter du café.
SCOUT                            Café, café... D'accord.
SCOUT                            Nous n'avons pas, hmm... Café...
AARON                            Tu veux sortir avec Maple?
SCOUT                            Well, je... Oui, j'aimerais bien.
AARON                            Tu pourrais essayer, mais c'est compliqué. aucun garçon n'est
AARON                            assez bien pour elle.
SCOUT                            Il est peut-être inutile d'essayer.
AARON                            C'est impossible de lui plaire.
AARON                            Croyez-moi, je la connais bien.
SCOUT                            Qu'est-ce que tu veux dire?
AARON                            Son type est les perdants qui pensent qu'ils sont meilleurs qu'ils ne le sont. Bien que de dire
AARON                            vrai. Je l'ai aussi vu sortir avec d'autres types de perdants. Peut-être que tu dois juste faire un effort pour avoir un peu plus confiance en toi, tu connais?
SCOUT                            Eh bien, c'est un bon début.
AARON                            Bonne chance avec elle, mec.
SCOUT                            Merci.

(Si consigo que Maple le dé una  oportunidad a estos cómics.)
(Entonces podríamos tener algo   en común.)
(...Pero eso no pasará ni en     mis mejores sueños.)
(Si je peux convaincre Maple de donner une chance à ces bandes dessinées.)
(Alors nous-autres pourrions avoir quelque chose en commun.)
(...Mais cela n'arrivera pas même dans mes rêves les plus fous.)

GUY                              ¿Te gustan los Time Raiders?
SCOUT                            Sí, no están nada mal.
GUY                              ¿Cuándo consigues los nuevos?
SCOUT                            Diana los trae cada semana.
GUY                              Qué alivio, pensé que no podría
GUY                              seguirla cuando me mudé aquí.
SCOUT                            Aunque hay una lista de espera.
SCOUT                            Tendrás que esperar a que Enoki
SCOUT                            los termine, a ella le flipan.
GUY                              Intentaré conseguirlos primero.
SCOUT                            Podrías hablarlo con ella.
GUY                              Eso haré.
GUY                              Aimez-vous Time Raiders?
SCOUT                            Oui, ils ne sont pas mal du tout.
GUY                              Quand est-ce que tu reçois les nouveaux?
SCOUT                            Diana les apporte chaque semaine.
GUY                              Quel soulagement, je pensais ne pas pouvoir la suivre quand j'ai déménagé ici.
SCOUT                            Bien qu'il y ait une liste d'attente.
SCOUT                            Il faudra attendre que Enoki les termine, elle les adore.
GUY                              Mo vais d'abord essayer de les avoir.
SCOUT                            Vous pourriez lui en parler.
GUY                              Mo vais le faire.

(Los cómics del mes pasado       siguen tirados en el suelo.)
(Lentamente acumulando polvo.)
(Les bandes dessinées du mois dernier traînent toujours sur le sol.)
(Pousse lentement la poussière.)

SCOUT                            Oye, a ti te gusta mucho leer
SCOUT                            libros, ¿no es así?
MAPLE                            A la vista está.
SCOUT                            ¿Crees que podrías prestarme
SCOUT                            algunos de tus libros?
MAPLE                            No te gustarían.
SCOUT                            Al menos quisiera intentarlo.
MAPLE                            ¿Te gustan los románticos? // ¿O los de época?
MAPLE                            ¿Las relaciones complicadas?
SCOUT                            Y... ¿No tienes de otro tipo?
MAPLE                            No, eso es lo que me gusta.
MAPLE                            ¿Acaso te hace sentir incómodo?
SCOUT                            ... Quizá un poco.
MAPLE                            Mejor sigue leyendo tus cómics.
SCOUT                            Hé, tu aimes vraiment lire des livres, n'est-ce pas?
MAPLE                            En vue ça l'est.
SCOUT                            Pensez-vous que vous pourriez me prêter certains de vos livres?
MAPLE                            Vous ne l'aimeriez pas.
SCOUT                            Au moins, j'aimerais essayer.
MAPLE                            Aimez-vous les romantiques? // Ou les vintage?
MAPLE                            Des relations compliquées?
SCOUT                            Et... Vous n'en avez pas d'autres?
MAPLE                            Non, c'est ce que j'aime.
MAPLE                            Cela vous met-il mal à l'aise?
SCOUT                            ...Peut-être un peu.
MAPLE                            Mieux vaut continuer à lire vos bandes dessinées.
//
SCOUT                            Podrían empezar a gustarme.
MAPLE						Dame un respiro.
//
SCOUT                            Je pourrais commencer à les aimer.
MAPLE                            Donnez-moi une pause.

SCOUT                            Oye, ¿Enoki?
ENOKI                            ¿Sí?
SCOUT                            ¿Podemos hablar de Maple?
ENOKI                            Oooh, ¿qué ocurre con ella?
ENOKI                            TE GUSTA Maple, ¿no es así?
SCOUT                            ¿Qué dices de gustar?
ENOKI                            Ya nos lo sabemos todos, jeje.
SCOUT                            Mierda, ¿tan obvio es?.
ENOKI                            Pero ella es complicada.
ENOKI                            Una vez le presenté a un chico.
SCOUT                            ¿Le presentaste a un chico?
ENOKI                            Y salieron durante un tiempo.
ENOKI                            Aunque se hartó y la dejó.
ENOKI                            Debes ser perfecto para ella.
SCOUT                            Y yo no lo soy.
ENOKI                            No sé quién podría serlo.
SCOUT                            Bueno, un hombre puede soñar.
ENOKI                            Aunque no tienes que cambiar.
ENOKI                            Sólo debes ser 'tú mismo'.
SCOUT                            Supongo que tienes razón.
ENOKI                            Darás con la chica adecuada.
SCOUT                            Está bien. Merci, Enoki.
ENOKI                            ¡De rien!
SCOUT                            Hé, Enoki?
ENOKI                            Oui?
SCOUT                            Peut-on parler de Maple?
ENOKI                            Oooh, qu'est-ce qui ne va pas avec elle?
ENOKI                            VOUS AIMEZ le Maple, n'est-ce pas?
SCOUT                            Que diriez-vous de l'aimer?
ENOKI                            Nous le savons tous déjà, hehe.
SCOUT                            Merde, c'est si évident?
ENOKI                            Mais elle est compliquée.
ENOKI                            Je l'ai présentée une fois à un garçon.
SCOUT                            L'avez-vous présentée à un garçon?
ENOKI                            Et ils sont sortis ensemble pendant un moment.
ENOKI                            Bien qu'il en ait eu marre et l'a quittée.
ENOKI                            Tu dois être parfait pour elle.
SCOUT                            Et je ne le suis pas.
ENOKI                            Je ne sais pas qui cela pourrait être.
SCOUT                            Well, un homme peut rêver.
ENOKI                            Vous n'avez pas à changer cependant.
ENOKI                            Vous n'avez qu'à être " vous-même ".
SCOUT                            Je suppose que tu as raison.
ENOKI                            Vous trouverez la bonne fille.
SCOUT                            D'accord. Merci, Enoki.
ENOKI                            De rien!!

SCOUT                            Oye, ten mucho cuidado con
SCOUT                            mi computadora, fue carísimo.
MAPLE                            No pensaba tocarlo. Aunque
MAPLE                            Ahora me da curiosidad...
SCOUT                            ¡Espera, por favor!
MAPLE                            ¡Que no voy a tocar tu trasto!
MAPLE                            Estos frikis y sus maquinitas...
SCOUT                            Hé, fais très attention avec mon computer, c'était très cher.
MAPLE                            Je n'allais pas y toucher. Même si
MAPLE                            Maintenant, je suis curieux...
SCOUT                            Attendez, s'il vous plaît!
MAPLE                            Je ne vais pas toucher à votre bric-à-brac!
MAPLE                            Ces monstres et leurs petites machines...

ENOKI                            Oye Scout, ¿tienes página web?
SCOUT                            ¡Sí! Aunque no es muy allá.
ENOKI                            ¿Me dejas verla?
SCOUT                            Ahora mismo no, aún no la acabé.
ENOKI                            Ah, vale.
ENOKI                            Ojalá tener mi propia página web.
ENOKI                            Seguro que es muy divertido.
SCOUT                            ¡Te aseguro que lo es!
ENOKI                            Hé Scout, avez-vous un site Web?
SCOUT                            Oui! Bien qu'il ne soit pas très là.
ENOKI                            Me laisserez-vous la voir?
SCOUT                            Pas maintenant, je ne l'ai pas encore fini.
ENOKI                            Oh, d'accord.
ENOKI                            J'aimerais avoir mon propre site web.
ENOKI                            C'est sûr que c'est très amusant.
SCOUT                            Je vous assure que oui!

AARON                            ¿Has oído hablar del efecto 2000?
SCOUT                            Por supuesto.
AARON                            ¿A ti te ocurrió algo?
SCOUT                            No, no me pasó mucho en realidad.
SCOUT                            Una aplicación me dio un 
SCOUT                            problema bastante extraño.
SCOUT                            Tenía un programa para organizar
SCOUT                            la compra y añadió toneladas de
SCOUT                            limpiazapatos a la lista. A día
SCOUT                            de hoy, 5 de Marzo, son 192000.
AARON                            Eso son son unos cuantos, ¿eh?
SCOUT                            Es cierto, provocó errores en
SCOUT                            montones de programas. Provocando
SCOUT                            bugs realmente extraños.
AARON                            Avez-vous entendu parler de l'effet de l'an 2000?
SCOUT                            Bien sûr.
AARON                            Il vous est arrivé quelque chose?
SCOUT                            Non, ça ne m'est pas vraiment arrivé beaucoup.
SCOUT                            Une application m'a donné un problème plutôt étrange.
SCOUT                            avait un programme pour organiser l'achat et a ajouté des tonnes de cirages à la liste. Un jour
SCOUT                            pour aujourd'hui, le 5 mars, est de 192 000.
AARON                            C'est pas mal, hein?
SCOUT                            Certes, cela provoque des erreurs dans de nombreux programmes. Provoquant des bugs vraiment bizarres.

(Me gradué como el mejor de clasecon un GPA de 3.99.)
(Ahora soy un científico viviendode una subvención corporativa.)
(Tengo un Computadora Castor 5000de última generación.)
(Que no puedo utilizar porque    olvidé mi propia contraseña.)
(Me cuesta dormir por las        noches pensando en ello...)
(J'ai obtenu mon diplôme en tête de ma classe avec un GPA de 3,99.)
(Je suis maintenant un scientifique vivant d'une subvention d'entreprise.)
(J'ai un computer Castor 5000 à la pointe de la technologie.)
(Que je ne peux pas utiliser car j'ai oublié mon propre mot de passe.)
(J'ai du mal à dormir la nuit en y pensant...)

(Esto parece muy caro...)
(No debería toquetearlo.)
(Cela a l'air très cher...)
(Vous ne devriez pas bricoler.)

(Esta fórmula verde hace que las plantas crezcan enormes.)
(Me pregunto qué pasaría si la   usara yo...)
(Tal vez podría conseguir poderesrelacionados con plantas...)
(Sería arriesgado por mi parte,  podría morirme si la pruebo.)
(Pero definitivamente podría     valer la pena intentarlo...)
(Cette formule verte rend les plantes énormes.)
(Je me demande ce qui se passerait si je l'utilisais...)
(Peut-être pourrais-je obtenir des pouvoirs liés aux plantes...)
(Ce serait risqué de ma part, je pourrais mourir si j'essaye.)
(Mais ça vaut vraiment le coup d'essayer...)

SCOUT                            ¡Cuidado!
SCOUT                            ¡Muchas de estas cosas son
SCOUT                            MORTALMENTE TÓXICAS!
SCOUT                            Attention!
SCOUT                            Beaucoup de ces choses sont
SCOUT                            TOXIQUE MORTEL!

SCOUT                            ¡Bonjour! ¿Eres Olivier?
OLIVIER                          ¡Oui! ¿Y tú eres Scout, no?
SCOUT                            En efecto, soy yo. ¡Bienvenido!
OLIVIER                          ¡Todo este lugar es increíble!
SCOUT                            He sido sincero en el anuncio.
OLIVIER                          ¿Eres un científico?
SCOUT                            Podría decir que lo soy.
SCOUT                            Aunque hago un poco de todo.
OLIVIER                          ¿Y vives bajo tierra?
SCOUT                            Tengo una máquina que excava
SCOUT                            búnkers con suma facilidad.
SCOUT                            Podría excavar hasta límites
SCOUT                            insospechados si así quisiera.
OLIVIER                          ¡Brutal! Oye, ¿vienes a la 
OLIVIER                          casa de los Tremblay a cenar?
SCOUT                            ¡Por supuesto!
OLIVIER                          ¡Mola! Nos vemos allí entonces.
SCOUT                            Bonjour! Vous êtes Olivier?
OLIVIER                          Oups! Et vous êtes un scout, n'est-ce pas?
SCOUT                            En effet, c'est moi. Bienvenue!
OLIVIER                          Tout cet endroit est incroyable!
SCOUT                            J'ai été sincère dans l'annonce.
OLIVIER                          Vous êtes scientifique?
SCOUT                            Je pourrais dire que je le suis.
SCOUT                            Même si je fais un peu de tout.
OLIVIER                          Et vous vivez sous terre?
SCOUT                            J'ai une machine qui creuse des bunkers très aisés.
SCOUT                            Je pourrais creuser jusqu'à des limites insoupçonnées si je le voulais.
OLIVIER                          Brutal! Hé, tu viens dîner chez les Tremblay?
SCOUT                            Bien sûr!
OLIVIER                          Cool! Rendez-vous là-bas alors.

ELEANOR                          ¡Bonjour, monsieur!
SCOUT                            ¡Bonjour! ¿Eres Eleanor?
ELEANOR                          ¡Oui! Encantada de conocerte.
ELEANOR                          ¡Este lugar es una pasada!
SCOUT                            He sido sincero en el anuncio.
ELEANOR                          ¿Eres un mago?
SCOUT                            Podría decir que lo soy.
SCOUT                            Aunque hago un poco de todo.
ELEANOR                          ¿Y vives bajo tierra?
SCOUT                            Tengo una máquina que excava
SCOUT                            búnkers con suma facilidad.
SCOUT                            Podría excavar hasta límites
SCOUT                            insospechados si así quisiera.
ELEANOR                          ¡Qué fascinante!
SCOUT                            Aw, ¡merci!
ELEANOR                          ¿Te veo luego en la cena?
SCOUT                            ¡Claro!
ELEANOR                          ¡Maravilloso!
ELEANOR                          Bonjour, monsieur!
SCOUT                            Bonjour! Êtes-vous Eleanor?
ELEANOR                          Oui! Ravi de vous rencontrer.
ELEANOR                          Cet endroit est incroyable!
SCOUT                            J'ai été sincère dans l'annonce.
ELEANOR                          Êtes-vous un magicien?
SCOUT                            Je pourrais dire que je le suis.
SCOUT                            Même si je fais un peu de tout.
ELEANOR                          Et vous vivez sous terre?
SCOUT                            J'ai une machine qui creuse des bunkers très facilement.
SCOUT                            Je pourrais creuser jusqu'à des limites insoupçonnées si je le voulais.
ELEANOR                          Comme c'est fascinant!
SCOUT                            Ah, merci!
ELEANOR                          On se voit plus tard au dîner?
SCOUT                            Bien sûr!
ELEANOR                          Merveilleux!

DIANA                            ¡Bonjour! Hey, ¿eres Scout?
SCOUT                            ¡Bonjour! ¿Eres Diana?
DIANA                            ¡Oui! ¡Es un placer conocerte!
DIANA                            Tío, ¡este sitio está guapísimo!
SCOUT                            He sido sincero en el anuncio.
DIANA                            ¿Eres científico o algo así?
SCOUT                            Podría decir que lo soy.
SCOUT                            Aunque hago un poco de todo.
DIANA                            ¿Y vives bajo tierra?
SCOUT                            Tengo una máquina que excava
SCOUT                            búnkers con suma facilidad.
SCOUT                            Podría excavar hasta límites
SCOUT                            insospechados si así quisiera.
DIANA                            ¡Qué pasote!
SCOUT                            ¡Merci!
DIANA                            ¿Vienes a cenar?
SCOUT                            ¡Claro!
DIANA                            ¡Genial!
DIANA                            Bonjour! Hey, tu es scout?
SCOUT                            Bonjour! Vous êtes Diane?
DIANA                            Oui! C'est un plaisir de te connaître!
DIANA                            Mec, cet endroit est magnifique!
SCOUT                            J'ai été sincère dans l'annonce.
DIANA                            Tu es scientifique ou quoi?
SCOUT                            Je pourrais dire que je le suis.
SCOUT                            Même si je fais un peu de tout.
DIANA                            Et vous vivez sous terre?
SCOUT                            J'ai une machine qui creuse des bunkers très facilement.
SCOUT                            Je pourrais creuser jusqu'à des limites insoupçonnées si je le voulais.
DIANA                            Que s'est-il passé!
SCOUT                            Merci!
DIANA                            Vous venez dîner?
SCOUT                            Bien sûr!
DIANA                            Génial!

(Ojalá pudiera conseguir algo    que me hiciera feliz.)
(Después de pasar tanto tiempo   estudiando, aquí estoy...)
(Y no sé. Paso de una cosa a     otra.)
(No puedo hacer algo sin querer  dejarlo a medias en el camino.)
(Tan sólo desearía ser feliz     donde estoy ahora, por una vez.)
(J'aimerais pouvoir obtenir quelque chose qui me rendrait heureux.)
(Après avoir passé tant de temps à étudier, me voilà...)
(Et je ne sais pas. Je passe d'une chose à l'autre.)
(Je ne peux pas faire quelque chose sans vouloir le laisser à mi-chemin.)
(J'aimerais juste être heureux là où je suis maintenant, pour une fois.)

SCOUT                            ¡Cuidado!
SCOUT                            ¡Muchas de estas cosas son
SCOUT                            MORTALMENTE TÓXICAS!
SCOUT                            Aunque bueno, tú ya sabías eso.
SCOUT                            O al menos, eso espero.
SCOUT                            Attention!
SCOUT                            Beaucoup de ces choses sont
SCOUT                            TOXIQUE MORTEL!
SCOUT                            Eh bien, vous le saviez déjà.
SCOUT                            OU du moins, je l'espère.

SCOUT                            ¡Bonjour! Eres Guy, ¿no es así?
GUY                              Oui. Y tú eres, Scout. ¿Cierto?
SCOUT                            ¡Bienvenu! ¿Te gusta tu cabaña?
GUY                              No bromeabas con eso que dijiste
GUY                              acerca de la cocina, ¿eh?
SCOUT                            ¡En absoluto!
GUY                              No parecen haber muchas personas
GUY                              por aquí, y sabes que no voy
GUY                              a poder cocinar mucha comida
GUY                              si no dispongo de clientes.
GUY                              ¿Cuánto tiempo tendrá que pasar
GUY                              hasta que se llene esto de gente?
SCOUT                            No debería pasar tanto tiempo.
GUY                              ¿Puedo fiarme de ti?
SCOUT                            Sans doute.
GUY                              Tres bien alors.
SCOUT                            Bonjour! Vous êtes Guy, n'est-ce pas?
GUY                              Oui. Et vous l'êtes, Scout. Certain?
SCOUT                            Bienvenu! Vous aimez votre cabane?
GUY                              Tu ne plaisantais pas avec ce que tu as dit à propos de la cuisine, n'est-ce pas?
SCOUT                            Pas du tout!
GUY                              Il ne semble pas y avoir beaucoup de monde ici, et tu sais que je ne pourrai pas cuisiner beaucoup si je n'ai pas de clients.
GUY                              Combien de temps cela prendra-t-il jusqu'à ce que ce soit rempli de monde?
SCOUT                            Cela ne devrait pas prendre si longtemps.
GUY                              Puis-je te faire confiance?
SCOUT                            Sans doute.
GUY                              Trois bien alors.

ENOKI                            ¿Salut? Scout, ¿estás aquí abajo?    
SCOUT                            ¡Sí! ¡Estoy aquí! ¿Dónde se ha   metido Aaron?
ENOKI                            Ha salido para ver cómo están    los demás.
SCOUT                            Menos mal. Hey, Maple. ¿Te       encuentras bien?
SCOUT                            Pareces agotada.
MAPLE                            ¿Qué tal si cierras el pico?     ¿Cómo no voy a estarlo?
MAPLE                            Después de TODO lo que ha pasado esta mañana.
SCOUT                            Oh- Está bien...
SCOUT                            Hey Enoki, ¿cómo luce todo por   aquí?
ENOKI                            Bien, es sólo que... Hay un      ruido extraño y fuerte.
ENOKI                            Aaron se asustó y quiso que nos  mantuviéramos a salvo.
SCOUT                            Creo en su intuición.
ENOKI                            Bonjour? Scout, es-tu ici?
SCOUT                            Oui! Je suis ici! Où était Aaron?
ENOKI                            Il est sorti pour voir comment vont les autres.
SCOUT                            Dieu merci. Salut le Maple. Tu te sens bien?
SCOUT                            Vous avez l'air épuisé.
MAPLE                            Et si vous la fermiez? Comment puis-je ne pas l'être?
MAPLE                            Après TOUT ce qui s'est passé ce matin.
SCOUT                            Oh- D'accord...
SCOUT                            Hey Enoki, comment ça va ici?
ENOKI                            Eh bien, c'est juste... Il y a un bruit fort étrange.
ENOKI                            Aaron a eu peur et voulait que nous-autres restions en sécurité.
SCOUT                            Je crois en ton intuition.
    
AARON                            ¿Qué diablos está pasando ahí    fuera?
SCOUT                            Es Rufus. Creo que se comió algo raro.
ENOKI                            Jeje, también me pasa después de comer la comida de Guy.
SCOUT                            No, puede ser algo serio. Tiene  que ver con mi investigación.
AARON                            Oh, ¿así que el científico va a  revelarnos lo que ha estado  
AARON                            haciendo en ese misterioso búnkerdurante los últimos meses?
SCOUT                            Soy un científico de la tierra,  pero lo cierto que que también
SCOUT                            investigo las plantas.
ENOKI                            ¡No me digas!
OLIVIER                          ¿Y por qué no me lo dijiste?
SCOUT                            No podía, es confidencial.
SCOUT                            Verás, resulta que esta planta   crece nativamente en estas
SCOUT                            islas, y muchas personas tienden a creer que es magia. Puede      
SCOUT                            hacerte tener visiones.
ENOKI                            ¿Cómo las setas?
SCOUT                            Las setas hacen que las personas tengan distintas visiones. Pero
SCOUT                            esta flor hace que todos tengan  la misma. Por eso la estamos
SCOUT                            investigando. No es como         colocarse, algo extraño e  
SCOUT                            inusual ocurre con ella.
SCOUT                            Aunque todos vean lo mismo,      reaccionan diferente debido     
SCOUT                            a un desequilibrio químico.      Sus visiones son tan 
SCOUT                            preocupantes y devastadoras,     que provocan que   
SCOUT                            aquellos que entren en           contacto entren en pánico.
ELEANOR                          ¿Y qué es lo que ven?
SCOUT                            No se sabe. Los afectados        prefieren guardar silencio.
SCOUT                            Las personas que la consumen     muestran un halo azul en los 
SCOUT                            ojos. No parecen durar por       siempre, pero son notorios  
SCOUT                            por un tiempo. Estuve mirando    las grabaciones de Rufus,    
SCOUT                            y como suponía... padece los     efectos de los halos azules.
AARON                            ¿Entonces se ha convertido en    supervillano o algo así?    
SCOUT                            No lo sé. Rufus no es muy...     grande, ¿sabes? Puede que- 
AARON                            Qu'est-ce qui se passe là-bas?
SCOUT                            C'est Rufus. Je pense qu'il a mangé quelque chose de bizarre.
ENOKI                            Hehe, ça m'arrive aussi après avoir mangé la nourriture de Guy.
SCOUT                            Non, ça pourrait être quelque chose de grave. C'est lié à mes recherches.
AARON                            Oh, alors le scientifique va nous-autres révéler ce qu'il fait dans ce mystérieux bunker depuis quelques mois?
SCOUT                            Je suis un scientifique de la terre, mais la vérité est que je fais aussi des recherches sur les plantes.
ENOKI                            Ne me dis rien!
OLIVIER                          Et pourquoi tu ne me l'as pas dit?
SCOUT                            Je ne peux pas, c'est confidentiel.
SCOUT                            Vous voyez, il s'avère que cette plante pousse nativement sur ces îles, et beaucoup de gens ont tendance à croire que c'est magique. Cela peut vous donner des visions.
ENOKI                            Comment les champignons?
Les champignons SCOUT font que les gens ont des visions différentes. Mais cette fleur fait que tout le monde a la même chose. C'est pourquoi nous-autres enquêtons dessus. Ce n'est pas comme se défoncer, quelque chose d'étrange et d'inhabituel se passe avec elle.
SCOUT                            Bien qu'ils voient tous la même chose, ils réagissent différemment en raison d'un déséquilibre chimique. Ses visions sont si troublantes et dévastatrices qu'elles font paniquer ceux avec qui elle entre en contact.
ELEANOR                          Et que voient-ils?
SCOUT                            Je ne sais pas. Les personnes concernées préfèrent garder le silence.
SCOUT                            Les personnes qui en consomment présentent un halo bleu dans les yeux. Ils ne semblent pas durer éternellement, mais ils sont perceptibles pendant un certain temps. J'ai regardé les cassettes de Rufus,
SCOUT                            et comme prévu... souffrant des effets de halos bleus.
AARON                            Alors est-il devenu un super-vilain ou quoi?
SCOUT                            Je ne sais pas. Rufus n'est pas très... grand, tu connais? Peut-être-

SCOUT                            Uhh.... Creo que hay algo en la  puerta.
AARON                            Tengo mi hacha a mano.
SCOUT                            Hey, os diré algo.               ¿Saben acerca de la excavadora
SCOUT                            de búnkers que tengo?
AARON                            ¿Sí...?
SCOUT                            Os diré qué podemos hacer. ¿Y si excavamos un túnel que nos
SCOUT                            lleve fuera de la isla? De       todas formas ya planeaba hacer 
SCOUT                            uno hasta la orilla.
SCOUT                            (Quería guardarme esto para la   Scout Expo, pero, uh...)
SCOUT                            (Tampoco es que tenga mucha      opción ahora mismo.)
ELEANOR                          ¿Es seguro?
SCOUT                            Euh... Je pense qu'il y a quelque chose sur la porte.
AARON                            J'ai ma hache à portée de main.
SCOUT                            Hé, je vais te dire quelque chose. Connaissez-vous la pelleteuse de bunker que j'ai?
AARON                            Oui...?
SCOUT                            Je vais vous dire ce que nous-autres pouvons faire. Et si on creusait un tunnel qui nous-autres emmènerait hors de l'île? Quoi qu'il en soit, je prévoyais déjà d'en faire un jusqu'au rivage.
SCOUT                            (Je voulais garder ça pour l'Expo Scout, mais, euh...)
SCOUT                            (Pas qu'il ait beaucoup de choix en ce moment non plus.)
ELEANOR C'est sûr?

SCOUT                            Vámonos.
ENOKI                            ¿Allons-y?
SCOUT Allons-y.
ENOKI Allons-y!

Observas la obra de arte.
Y por lo tanto....
La obra de arte te observa a ti.
El arte es extraño.
Vous regardez l'œuvre d'art.
Et par conséquent....
L'œuvre d'art vous observe.
L'art est étrange.

- MÁS CASAS POR ESTE CAMINO -
- PLUS DE MAISONS CETTE ROUTE -

MAPLE                            Quizá deba ir a lo de Scout.
MAPLE                            Je devrais peut-être aller chez Scout.
    


 - WISHING POND -                DOESN'T WORK BUT FEEL FREE TO USEIT IF YOU'RE DESPERATE
The rocks in the way don't even  let you get a great view.
Maybe if you could see over the  rocks, you could throw a coin in to make a wish.
This wasn't thought through very well.

 - LE MAISON DE LANDRY -

 - DIANA -
Either refers to the house or    the person.

- SOME RANDOM GUY'S HOUSE -
No one has moved in yet, you see.
    
- GUY'S HOUSE -
Someone named guy has moved in,  you see.

~ JARGINS NOIRS ~

MAPLE                            Oh, hey. So you're Eleanor?
ELEANOR                          Oui! Enchante de faire votre     connaissance.
MAPLE                            Egalement. You seem...           No offense,
MAPLE                            A little old-fashioned?
ELEANOR                          Oh, it's just what we're used to.
ELEANOR                          It's so nice to be so far away
ELEANOR                          from the city again. I had       forgotten how
ELEANOR                          sentimental I was for the trees.
MAPLE                            I see. And you're her husband,   j'suppose?
OLIVIER                          Oui, I'm Olivier.
ELEANOR                          He doesn't always talk much, but he makes it count.
ELEANOR                          I met him in a garden, and he    taught me how to read.
OLIVIER                          She's more special, though. She  just about saved my life.
MAPLE                            Oh, how so?
OLIVIER                          It's not important-
ELEANOR                          From my mother.
MAPLE                            Ah, I know how that is, haha.
ELEANOR                          You do? She was going to drain   all his blood for a ritual.
MAPLE                            I... Hmm, well, alright then.    That's.. not what I expected.
MAPLE                            Nice to meet y'all, I guess?
ELEANOR                          Bien sur! I'm baking your family a pie right now as our 'merci'.
MAPLE                            C'est bon, just no, uh, weird    ingredients, haha.
MAPLE                            (What was Scout thinking inviting these weirdos?!)

ENOKI                            Bienvenue, y'all!! Je suis Enoki!Ravie de vous autres rencontrer!
ELEANOR                          Bonjour! Enchante de faire votre connaissance.
OLIVIER                          Bonjour!
ELEANOR                          I'm Eleanor, and this is my      husband Olivier.
ENOKI                            I love your dress!! Where did youget it from?
ELEANOR                          Oh! I made it myself. I love yourdress, too!
ENOKI                            That's soo cool!!
ENOKI                            We look like we're about the samesize, maybe we can trade someday!
OLIVIER                          So, Scout said that you and your husband are royalty?
ENOKI                            Oh yes! This is our little       kingdom, but we're not cruel.
ENOKI                            I'm like the chillest queen      you'll ever meet.
ENOKI                            You guys wanna be a duke and     duchess?
ELEANOR                          I.. no thank you, I don't think  I know what those are.
OLIVIER                          Merci, en tout cas.
ENOKI                            Bien sur! N'importe quand!

AARON                            Bienvenu! Olivier and Eleanor,   I presume?
ELEANOR                          Oui oui!
OLIVIER                          So, I take it that you're 'king' of this island?
AARON                            Is that what Scout told you?     I suppose you could say that.
AARON                            I never graduated high school,   so I'm not cut out for anything
AARON                            but work like this, but I didn't want to spend my life in a
AARON                            factory. So, my wife Enoki and I had the idea to spend our savings
AARON                            on some land and live off the    grid. The 'royalty' thing was
AARON                            her idea, and she was very cute  about it, so I had to say yes.
AARON                            She's probably offered           aristocratic roles to y'all.
OLIVIER                          Oh - Aaron, was it? Thank you forclearing out the area for the
OLIVIER                          greenhouse. I'll be able to grow all sorts of things to share.
ELEANOR                          And I adore this cabin! In a goodway, it reminds me of home.
ELEANOR                          Vee and I were so excited to hear about this island.
AARON                            Well, we're all very happy to    have you as well!
AARON                            If my little sister gives either of you a hard time,
AARON                            She doesn't mean anything by it, I promise.
AARON                            Hop on by to trailer tonight,    we'll have some dinner ready.
OLIVIER                          Encore une fois, je vous remerciesincerement.
AARON                            We're family, now - please, 'tu' is plenty.

SCOUT                            Hey, y'all! I'm Scout, from      online?
OLIVIER                          Ah! Enchante de faire votre      connaissance.
ELEANOR                          Oh... But from your picture, I   thought that you...
SCOUT                            You thought that I what?
ELEANOR                          I thought you were a skeleton.
SCOUT                            Oh- Well, that's just 'cuz I use the photo of a character I like.
SCOUT                            There's this skeleton from a     comic named Seemore.
SCOUT                            He's got magic powers and a- well maybe I should just let you
SCOUT                            read the comic, it's a ton of    fun.
ELEANOR                          What's a comic?
SCOUT                            I... huh, I've never had to      answer that question before.
SCOUT                            They're like books, but they've  got pictures, but-
ELEANOR                          Those sound so cool!
OLIVIER                          Eleanor was raised in a cult, so she doesn't know much about
OLIVIER                          the outside world. That's one of the reasons we wanted to move
OLIVIER                          here, so we could have a little  break from her extended family.
SCOUT                            Oh.. Well, crap. Welcome to the  island, I guess.
SCOUT                            Queen Enoki's got dibs on my     latest Time Raiders,
SCOUT                            But when she's done, I'll        definitely get you the copy.
ELEANOR                          Merci!!

OLIVIER                          Eleanor, why'd you turn the stoveon? Aren't we eating with
OLIVIER                          the Tremblays tonight?
ELEANOR                          Oh, yes yes, I just couldn't helpmyself.
ELEANOR                          I haven't seen a stove like this since I was so little.
ELEANOR                          I wanted to try and make some    toast.
OLIVIER                          What do you think of this place?
OLIVIER                          There aren't many people, are yougoing to get lonely?
ELEANOR                          Well, are you going to be lonely?
OLIVIER                          I just wish my grandfather could see us, now.
OLIVIER                          I think he'd be so proud of you.
ELEANOR                          Maybe he can see us from heaven.
ELEANOR                          Maybe mama has changed in heaven and thinks well of you, now.
OLIVIER                          I don't suppose either of us can know, but I won't be lonely.
OLIVIER                          I haven't really been lonely     since I got to know you.
ELEANOR                          Vee, I hope that we don't ever   feel differently.
ELEANOR                          I've seen how my parents became. I already feel older.
ELEANOR                          I know that once we have our own enfants...
OLIVIER                          How is your sister doing?
ELEANOR                          She's always exhausted. She jokesabout grey hair, but I think
ELEANOR                          she really does have grey hairs. But she's different.
ELEANOR                          The things she was so upset aboutare meaningless, now.
OLIVIER                          Maybe it'll be the same with us. Let's just be patient.
ELEANOR                          It'll be strange to have married friends our age. Do you think
ELEANOR                          Diana will be jealous?
OLIVIER                          I think she'll have a great time here. S'il te plait detends-toi!
ELEANOR                          Je suppose que tu as raison, Vee.

DIANA                            Aw, super! I love it, it's so    cozy in here.
DIANA                            I hope y'all don't mind me spend-ing ungodly amounts of time here.
ELEANOR                          Of course not! As long as you    don't mind helping sometimes.
OLIVIER                          Remember, living like this means that we're going to work hard.
OLIVIER                          I'll probably be spending most ofmy time chopping wood, or
OLIVIER                          working out in the garden pullingweeds and watering.
ELEANOR                          You said that you were interestedin working for the boat captain?
DIANA                            Oh, yes. I'll be going down to   the docks today, in fact.
DIANA                            Maybe I'll be a proper boat      captain before too long!
ELEANOR                          I know you'll do great, Diana!
OLIVIER                          This isn't what you thought you'dbe doing at 22, huh?
DIANA                            Well, I guess I didn't know what I thought I'd be doing.
DIANA                            Y'all didn't think you'd be      moving here, huh?
OLIVIER                          I supposed I'd probably still be working with plants, that's it.
ELEANOR                          I'm still alive and so is Vee,   and that's all I could want.
DIANA                            Yeah.. Please stay that way, why don't you two?

MAPLE                            Salut, guys.
ELEANOR                          Salut, Maple! Do you want some   stew? I baked some.
MAPLE                            Oh, that sounds great! I'd love  some, your stew is amazing.
OLIVIER                          Diana brought a new board game infrom inland, we were interested
OLIVIER                          in playing it tonight. Would you like to invite the others?
MAPLE                            But not me? Excuse you, haha.
MAPLE                            Hey, um.. I'm sorry about last   week's board game.
ELEANOR                          It's very fine, Maple. It's very easy to get angry in games.
MAPLE                            Your cabin doesn't seem to smell like smoke anymore, though.
ELEANOR                          Have you tried the new islander'sgumbo yet?
MAPLE                            Are you asking me if I feel      threatened by it? No, not yet.
MAPLE                            There's nothing that adding more Tabasco can't fix.
MAPLE                            Look, I know I don't see you guysall the time, but-
MAPLE                            Thanks for your ingredients.     Y'all are a godsend.
OLIVIER                          Thank you for your work, too. I  will admit, it didn't make any
OLIVIER                          sense that this island would workon its own.
OLIVIER                          It's almost like you have a good luck charm.
MAPLE                            Yeah... Anything that Enoki wantsis something she gets.
MAPLE                            It's only a matter of time beforeshe doesn't get something that
MAPLE                            she wants and she throws a fit,  though.
OLIVIER                          I see. Well, if there's anything we can do for you, let us know.
MAPLE                            Same for you both.


ENOKI                            Salut!! How are you two today?
ELEANOR                          We're doing well! Would you like some stew?
ENOKI                            Don't mind if I 'dew', hehe.
OLIVIER                          You coming to the game night     tonight?
ENOKI                            I wouldn't miss it for anything!
ELEANOR                          Have you met the new islander    yet?
ENOKI                            Don't tell Maple....
ENOKI                            -but I think his gumbo is better.
ENOKI                            You can NOT tell Maple I said    that though.
ELEANOR                          My lips are sealed.
ENOKI                            Hey, you two have a sewing       machine in here?
ELEANOR                          Oui.
ENOKI                            You said you make your own       clothes, oui? You, uh..
ENOKI                            Wouldn't mind giving me a lesson or two?
ELEANOR                          Pas du tout! I would love to     teach you anytime!

AARON                            Salut! I heard that you wanted tohave a game night tonight?
ELEANOR                          Oui oui! Although, we would like to have it outside under a tree.
ELEANOR                          I made a quilt that should be bigenough for all of us.
AARON                            Outside just in case Maple gets..upset this time, oui?
OLIVIER                          Oui, haha.
ELEANOR                          We made some stew if you want    some.
AARON                            I already had some of Maple's    leftover gumbo, but merci!
AARON                            Speaking of, Guy has been pretty reserved, but he seems nice.
AARON                            I'm just excited to have more    people on the island.
OLIVIER                          We're becoming a proper little   village, aren't we?
AARON                            Yeah, yeah I guess so.
OLIVIER                          Are you alright, Aaron? You look long in the face.
AARON                            Yes, I'm just thinking. Maple andI aren't doing so well.
OLIVIER                          What do you mean?
AARON                            Well, she doesn't want to move   out, but she needs to.
OLIVIER                          Can't you just ask her to? Aren'tyou king or something?
AARON                            I can. Maybe I should. She's justlike this.
AARON                            She goes back and forth between  being super independent, and
AARON                            then the next day, she's clingy.
OLIVIER                          This sounds like something you   should take up with her, not us.
AARON                            You're right, you're right.

SCOUT                            Hey, y'all! Scout here.
ELEANOR                          Salut! Would you like some stew?
SCOUT                            Merci, but I ate just.. uh.. holdon, the last time I ate..
SCOUT                            Holy cow, I haven't eaten yet.   I'd love some stew!
ELEANOR                          Hehe, of course.
SCOUT                            You guys catch my Scout TV reportthis morning?
ELEANOR                          Oh, we don't have a television.
SCOUT                            Right, right.. Forgot about that,I'm sorry.
SCOUT                            Anyway, apparently my broadcast  was hacked.
OLIVIER                          Hacked? By whom?
SCOUT                            No clue. The Tremblays aren't    worried about it, though.
ELEANOR                          Will you be coming to our game   night tonight?
SCOUT                            I'll do my best, there's stuff I gotta do for work.
SCOUT                            We'll see how that goes.
OLIVIER                          Well, we'll save you a seat.
SCOUT                            Merci!
ELEANOR                          De rien!

OLIVIER                          So, your birthday is coming up ina week...
ELEANOR                          Oui?
OLIVIER                          I would surprise you, but I don'twant to disappoint you with-
ELEANOR                          ...
OLIVIER                          ...Do you want me to just        surprise you?
OLIVIER                          ...
OLIVIER                          Are you still thinking about thatceremony?
ELEANOR                          I'm never going to forget that   night, not ever.
ELEANOR                          I can't decide if it's a good or a bad feeling.
ELEANOR                          You gave me enough of a birthday gift for the rest of my life.
OLIVIER                          But you wouldn't complain if I   got you a new sewing machine.
ELEANOR                          ...
OLIVIER                          Not saying that it's what I'm    going to get for sure, but..
ELEANOR                          Don't you have some vegetables to prune? I need to get started
ELEANOR                          on canning for the winter.
OLIVIER                          Right, right, just uh-...        Yeah, nevermind.

DIANA                            Alright, guys, we have to talk.
OLIVIER                          What's up?
DIANA                            Some dude hacked Scout's TV      program this morning.
DIANA                            He was a Mons d'Plonj, I think?  He was threatening the island.
ELEANOR                          O-Oh.. Oh no.. He wasn't with thewitches, was he?
ELEANOR                          Vee, have they found us?
DIANA                            No, he looked like some twerp.   Apparently Maple knows him?
DIANA                            The Tremblays aren't worried.
ELEANOR                          Oh.. Thank goodness..
DIANA                            Have you met that new guy up     north, though? Cesar?
DIANA                            He seems shady, but Enoki trusts him. He has a shop or something.
DIANA                            That new Guy.. er.. guy, he seemsfine. He makes good food.
OLIVIER                          Hey, El, calm down, you're going to hyperventilate.
ELEANOR                          I'm sorry.. I'm sorry..
DIANA                            Hey, Eleanor, it's going to be   okay. Wanna come to my place?
DIANA                            We can relax and eat snacks I    imported from inland.
DIANA                            Yes, that sounds like fun.       Merci.


ELEANOR                          Bonjour! You must be Guy.
GUY                              Oui. The name's Guy. Guy Pizza.
ELEANOR                          Guy... Pizza?
GUY                              It was funnier when I was a pizzaguy.
OLIVIER                          Well, welcome to the island!
GUY                              Nice to meet y'all. I'm gonna go back and finish setting up.
GUY                              I've always wanted a full-size   kitchen, and I'm gonna make good
GUY                              use of it, you'll see.
ELEANOR                          We're having a game night tonightand we were wondering,
ELEANOR                          Would you like to join us?
GUY                              I would, but I'm too excited     about this kitchen.
ELEANOR                          I.. see. I hope you have fun withyour kitchen.
GUY                              Oh, I will. I will.

ELEANOR                          What's going on outside?
AARON                            I don't know, but follow me,     we're going to wait this out in 
AARON                            Scout's bunker until we can get  things sorted.
AARON                            Where's Diana?
OLIVIER                          She's out boating with Guy today and won't be back for hours.
AARON                            Thank goodness. Follow me, I'll  get us out of here.

    This is Eleanor's library.

    The door is locked.
    You decide that it's probably notyour business.
    
MAPLE                            Hey! So, you're Diana?
DIANA                            Hiya! Finally! Another redhead!
MAPLE                            Oh, I'm not a redhead, I'm more  of a honey-blonde.
MAPLE                            I'm a wood elf, so it looks a bitorange sometimes.
DIANA                            Oh, you are? Then..
MAPLE                            Why are my ears round?
DIANA                            I don't want to ask if you don't feel comfortable.
MAPLE                            Oh, it's fine. They were clipped when I was a baby.
MAPLE                            I'm Maple, by the way.           Maple Tremblay.
DIANA                            Heureux de te rencontrer!
DIANA                            These cabins are so nice! You're,uh, older brother make em?
MAPLE                            Mostly. I go out and find gems inlocal caves sometimes.
MAPLE                            We make enough to live pretty    well out here.
DIANA                            Do you live in that trailer I sawmoving in?
MAPLE                            Yep. I'm on the couch.
DIANA                            Do you not want a cabin? One of  them looks empty.
MAPLE                            You see, Aaron and Enoki want to make a castle or something.
MAPLE                            I'm gonna take over their trailerwhen that happens.
DIANA                            So... is this place, like,       seriously a country?
MAPLE                            I mean.. if we act like it is,   then it is, isn't it?
DIANA                            Is it really that easy?
MAPLE                            Until we fight a war? We'll see. Nice to meet you.
DIANA                            Yeah, nice to meet you too!

ENOKI                            Hey!! Are you Diana?             I'm Enoki Tremblay!
DIANA                            Enchante de faire votre          connaissance!
ENOKI                            Is everything comfortable for youso far?
DIANA                            Dude, I'm still not sure if I'm  dreaming or not.
DIANA                            This feels way too good to be    real, it's crazy.
ENOKI                            I'm a pretty lucky gal, so when  I want something to happen, well,
ENOKI                            Things tend to turn out, and I   wanted this to turn out.
ENOKI                            I heard you've got somethin' withCapt. Nicholas?
DIANA                            Yeah! He's looking for someone totake over this area.
DIANA                            I'll eventually be ferrying      across Superieur.
ENOKI                            Aw, fun!! You gotta take us in a ride sometime.
ENOKI                            If you ever need us for anything,you let us know, alright?
DIANA                            D'accord!

DIANA                            Bienvenu! You're Aaron Tremblay, oui?
AARON                            Bienvenu! How's the cabin workingfor you?
DIANA                            Oh, it's perfect!! It feels too  good to be true, honestly.
DIANA                            I'm starting up my first boat    short introduction today.
DIANA                            Do you know Capt. Nicholas well?
AARON                            I'll be honest, I spend most of  my time chopping wood.
AARON                            But he seems like a very nice    person from what I know.
AARON                            I won't stay long, I was just    stopping by to check in.
AARON                            Just let me know if you need     anything, alright?
DIANA                            Absolutely! Thanks!

SCOUT                            Hey! It's me, Scout. Just wanted to introduce myself.
DIANA                            Ah! Nice to meet you! I'll admit I wasn't sure this was real.
DIANA                            I'm glad I wasn't.. you know..   killed or something.
SCOUT                            I'll admit, I'm actually a bit   new here, too-
SCOUT                            I moved over here from a nearby  island when I met the
SCOUT                            Trembalys and decided I'd jump   over here.
SCOUT                            It wasn't exactly easy diggint a new bunker, but it was
SCOUT                            worth it. It's nicer over here.
DIANA                            Well, you seem to be doing fine. You a scientist?
SCOUT                            Yeah, it's a little funny. This  company's got me here
SCOUT                            for some reason to do experimentsbut on an island? No clue why.
DIANA                            You find out anything cool?
SCOUT                            I made this device that makes    bunkers real fast.
SCOUT                            No idea what I'll use it for, butit's got potential.
DIANA                            Hey, you feel like making me a   bunker sometime?
SCOUT                            Aw sure, I'd love to!


DIANA                            Hey, Vee! Fancy seeing you here  in my /new cabin/, huh?
OLIVIER                          It only took you about a day to  make it look just like your
OLIVIER                          place back home, didn't it?
DIANA                            If all things go well, this'll beout new 'back home', right?
OLIVIER                          It all depends if we can trust   these people.
OLIVIER                          You've got something to defend   yourself on you, right?
DIANA                            Right, I have my flare gun on me.
DIANA                            I really home I never have to useit, though.
OLIVIER                          Me too. But they seem nice       enough.
OLIVIER                          At least they're not going to tryand sacrifice us, hehe.
DIANA                            Hehe, no kidding. If any of El's family shows up,
DIANA                            You're giving me a call, right?
OLIVIER                          Of course, of course.

ELEANOR                          It looks just like your room at  home!
DIANA                            Yep, did you expect anything lessfrom me? Hehe.
ELEANOR                          Well, I love it anyway. It's verycozy.
ELEANOR                          If you need anything, please let me know,
ELEANOR                          I have set up my room, and we now have a crystal ball room!
ELEANOR                          I'm still working on my summoningskills, they're rusty.
DIANA                            And you're absolutely sure that  using magic won't cause
DIANA                            Any.. er.. witches to find out   where we are?
ELEANOR                          I'm positive. I even think that  if this is good enough,
ELEANOR                          We can invite my family to come  by, I'd love to show them
ELEANOR                          this place. It seems peaceful.
DIANA                            We'll see. We haven't exactly hada peaceful life until now.
DIANA                            Hey, you seen those Tremblays yetor talked to them?
DIANA                            It feels like we've got one of   them for each of us.
DIANA                            They have a redhead and a couple with the 'farmer' type
DIANA                            and that Enoki seems cute, but   you're the cuter one.
ELEANOR                          Aw, Merci!
DIANA                            I can't help but be a little     suspicious, but I think
DIANA                            We're in for a good time.
ELEANOR                          Me too.

MAPLE                            Diana! Hey!
DIANA                            Hey, Maple!                      How's it shakin', bacon?
MAPLE                            Not bad, just a little bored.
DIANA                            Dude, you see that broadcast thismorning?
MAPLE                            With Rufus hijacking it? He's a  twerp, we're fine.
MAPLE                            He probably thinks he's a super  villain or something.
DIANA                            Boys like that just crack me up, seriously haha.
MAPLE                            Talk about it. But let me know ifyou spot him.
MAPLE                            Fried alligator's pretty tasty   this time of year.
DIANA                            Will do.
DIANA                            So what've you been up to lately?
MAPLE                            You seen Scout? Poor guy, he's   definitely got a crush on me.
MAPLE                            It's kind of sweet right now, butI'm eventually going to have to
MAPLE                            let him know he's really not my  type.
DIANA                            Girl, I don't envy you, haha.    So, what is your type?
MAPLE                            I want someone who makes me      excited and.. is loose, y'know?
MAPLE                            All these boys act like I'm a    goddess or something and it's
MAPLE                            kind of patronizing. I could makeem into a barbeque if I wanted.
DIANA                            Maybe that's why they treat you  like that, they're scared, hehe.
MAPLE                            I need to find another fire elf  somewhere, probably.
DIANA                            There aren't very many this far  southeast.
MAPLE                            Yeah, I'll keep looking then, I  guess, but it's a small island.
DIANA                            That it is, haha. You care care  of yourself, Maple.

ENOKI                            Hey, girl!
DIANA                            Enoki, ma cherie! You want some  snacks?
ENOKI                            I always want snacks.
DIANA                            Haha, of course. So what's your  day been like?
ENOKI                            Good, good, but I'm a little     worried.
DIANA                            Aw, how come?
ENOKI                            Well, it's about Aaron and Maple.They've been fighting.
DIANA                            That's not good! Do tell.
ENOKI                            Well, Aaron's always bottled up  how he feels about things,
ENOKI                            While Maple tells you to your    face and hurts feelings.
DIANA                            That's not a good combination.
ENOKI                            It always blows over, but it     makes me sad in the meantime.
DIANA                            I don't have siblings, but that'sjust how it goes, right?
ENOKI                            You a lonely only too? Yeah, I   always wanted a little sister.
DIANA                            Little bro for me. Less drama.
ENOKI                            True, true.
DIANA                            Keep me up to date, k?
ENOKI                            K.

DIANA                            Hey, Aaron!                      What can I do you for?
AARON                            Nothing much, you know about the game night tonight?
DIANA                            Yeah! I'm definitely coming. Hey,you saw that broadcast?
AARON                            I talked to Maple, and she seems to have known the Plonj guy.
AARON                            She's not worried about it.
DIANA                            Oh, thank goodness.              See ya tonight?
AARON                            Sure thing!

SCOUT                            Hey! It's me, Scout.
DIANA                            Hey Scout! What're you on about?
SCOUT                            It looks like this month's Scout TV is a wrap.
SCOUT                            Now I've just gotta worry about  the Scout Expo next month.
DIANA                            You keep bringing that up, what  is that exactly?
SCOUT                            Oh, it's this thing where I take all my inventions and I
SCOUT                            show em off. I usually take a    video and put it on the
SCOUT                            world wide web, but now I've     actually got friends to show
SCOUT                            the stuff off to!
DIANA                            Aw, that sounds like fun! What'veyou got, for example?
SCOUT                            No spoilers! Gotta wait for the  expo, you know.
DIANA                            Of course, of course.            That was a test.
SCOUT                            ...ok, so I made this device-
DIANA                            No, you can't tell me, remember?
SCOUT                            But I- I... hmm... okay, fine.   This is hard.
DIANA                            I figured it would be, hehe.

DIANA                            Hey, Vee! How'd you be?
OLIVIER                          Good, good.
DIANA                            You're not here to ask if I can  host the game night here, right?
OLIVIER                          No, no! Goodness.. We're doing itoutside.
OLIVIER                          If all goes well, we won't burn  down the island, haha.
OLIVIER                          Is everyone doing well back on   shore?
DIANA                            Wonderful! My parents want to    come up and visit sometime.
DIANA                            I need to clean up though.. maybeI pretend your place is mine.
OLIVIER                          In your dreams, haha.
OLIVIER                          I need to invite Eleanor and my  family up here sometime.
DIANA                            Oh, they'd love this place.
DIANA                            Hopefully nothing goes horribly  wrong.
OLIVIER                          Of course, of course haha.

ELEANOR                          Bonjour!
DIANA                            Salut, ma charie! Quoi de neuf?
ELEANOR                          Oh, is that sourdough I smell?
DIANA                            It shouldn't be, haha. I really  need to pick up my room...
DIANA                            How've you been lately? Any news?
ELEANOR                          Oh, nothing much. I've been      sewing a new quilt.
DIANA                            Fancy. What are you making it    out of?
ELEANOR                          I took all of my clothes from my home village to the island.
ELEANOR                          They're ready to retire, but I   can't bear to part from them.
ELEANOR                          They're so much of who I am, so  I'm making a quilt.
DIANA                            Aw, that's wonderful.
DIANA                            You been making any art lately?
ELEANOR                          A bit, a bit! There are so many  pretty landscapes here.
DIANA                            Oui. I could play guitar by the  ocean for the rest of my life.
DIANA                            Well, I say ocean, I mean lake.  Same difference.
DIANA                            Eleanor, I think I'm meant for   the sea.
ELEANOR                          That sounds like a fun life.
DIANA                            Arrrrrrrg, it's pirate time.
DIANA                            But it'll be okay, I'll visit allthe time when I'm sailing!
ELEANOR                          S'il vous plait!

DIANA                            Hey! Guy, was it? You that guy?
GUY                              Yeah, that's me. This your place?
DIANA                            You bet. It's not much. you like your place?
GUY                              Ever since I was a kid, it's beena dream to have my very own
GUY                              Industrial-sized kitchen that I  can roll out of bed to.
DIANA                            That's a pretty hyper-specific   dream, but I get it.
GUY                              You don't even have a kitchen, doyou?
DIANA                            I mean, I've got a stovetop and  a mini-fridge, haha.
DIANA                            I do all the importing here, so  I eat pre-packaged a lot.
GUY                              That's not super healthy y'know.
DIANA                            Yeah, I'll worry about that laterwhen it matters.
DIANA                            Everyone gets old and fat        someday, y'know.
GUY                              Not me. I'll be old and thin.
DIANA                            We'll catch up in fifty and see  how that's going, huh?
GUY                              You bet.
DIANA                            We're having game night tonight, you coming?
GUY                              Nah, I'll be messing with my     kitchen tonight.
DIANA                            Ah.. I see, I see. Fair enough.
DIANA                            You do you, dude.
GUY                              Will do.

OLIVIER                          O-Oh! Excuse me, ma'am. Where didyou come from?
GRAND-MÈRE CORINNE               This greenhouse is still quite   nice, was it moved?
OLIVIER                          Oh.. Well, I was told that it wastransported from inland.
GRAND-MÈRE CORINNE               Well, you see, I once owned this greenhouse, young man.
GRAND-MÈRE CORINNE               I don't see any point in having  ambiguity; I am a ghost.
OLIVIER                          A ghost???
GRAND-MÈRE CORINNE               It seems I am doomed to haunt    this greenhouse forever.
OLIVIER                          My apologize, that seems... it   seems like a terrible fate.
GRAND-MÈRE CORINNE               Would you consider it horrible tospend an eternity here?
OLIVIER                          Now that I think about it.. I    suppose not.
OLIVIER                          It's where I spend most of my    life anyway.
GRAND-MÈRE CORINNE               I see you enjoy taking care of   these plants, son.
GRAND-MÈRE CORINNE               Before I leave, I will remind youof one wisdom.
GRAND-MÈRE CORINNE               Even if your care of these plantsseems meaningless,
GRAND-MÈRE CORINNE               Wonderful things come to the     diligent.
GRAND-MÈRE CORINNE               It was very nice to meet you.    Until next time!
    
OLIVIER                          O-Oh! Excuse me, ma'am. Where didyou come from?
GRAND-MÈRE CORINNE               This greenhouse is still quite   nice, was it moved?
OLIVIER                          Oh.. Well, I was told that it wastransported from inland.
GRAND-MÈRE CORINNE               Well, you see, I once owned this greenhouse, young man.
GRAND-MÈRE CORINNE               I don't see any point in having  ambiguity; I am a ghost.
OLIVIER                          A ghost???
GRAND-MÈRE CORINNE               It seems I am doomed to haunt    this greenhouse forever.
OLIVIER                          My apologize, that seems... it   seems like a terrible fate.
GRAND-MÈRE CORINNE               Would you consider it horrible tospend an eternity here?
OLIVIER                          Now that I think about it.. I    suppose not.
OLIVIER                          It's where I spend most of my    life anyway.
GRAND-MÈRE CORINNE               I see you enjoy taking care of   these plants, son.
GRAND-MÈRE CORINNE               Before I leave, I will remind youof one wisdom.
GRAND-MÈRE CORINNE               Even if your care of these plantsseems meaningless,
GRAND-MÈRE CORINNE               Wonderful things come to the     diligent.
GRAND-MÈRE CORINNE               It was very nice to meet you.    Until next time!

CESAR'S BIZAAR                   'GONE FISHING, BE BACK FEB. 28th'

CESAR'S BIZAAR                   'WE ONLY HAVE TWO ITEMS,         DEAL WITH IT'

MAPLE                            So... Guy, you, uh.. put tomatoesin your Jambalaya?
GUY                              Just as God intended.
MAPLE                            Just as G- Just as God intended??
MAPLE                            ...You're kidding me, right?
GUY                              Let me guess, you're one-a those who likes her roux burnt.
MAPLE                            Define 'burnt'.
GUY                              Like so burnt, all the color's   gone and you can't taste it.
MAPLE                            What do you mean 'can't' taste   it? Of course you can!
GUY                              Yeah, cuz you bury it in a pile  of random spices.
MAPLE                            My spice choice is NOT random.
GUY                              Now if you'll excuse me, I don't need to sweep the kitchen
GUY                              floor to make a good jambalaya.
MAPLE                            You Creoles are psychotic.
GUY                              Not like you Cajuns are, honey.  I tell you what. Gumbo contest.
GUY                              You make some gumbo and we get   everyone else to judge. Deal?
MAPLE                            Deal.                            Easy.
    
ENOKI                            Ooooooo... I love your kitchen!! It's so big!
GUY                              Merci. I'm pretty keen on rollingout of bed to some cornbread.
ENOKI                            I wish I could do that, hehe.
GUY                              Say, uh.. That Maple belle, how'sher gumbo like compared to mine?
ENOKI                            Are you two in a competition?    Ooh, now I don't wanna choose.
ENOKI                            I don't wanna on your bad side   right as soon as you moved in,
ENOKI                            But you gotta know that Maple andI are like best friends.
GUY                              Maybe I can cook up something    that'll make you reconsider.
ENOKI                            That'll be pretty tough. I don't like food /that/ much.
GUY                              But... Ah, nevermind, have it    your own way, cheri.
    
AARON                            It smells so nice in here!
GUY                              Oui, as it ought to.
AARON                            So, uh.. I heard that you moved  in because you want customers?
GUY                              Right.
AARON                            Well, uh.. Obviously we're not a huge group of people here..
AARON                            And I'm obviously doing my best  to make this place a good home..
GUY                              Uh huh?
AARON                            I just, uh, hope you know that wearen't quite big enough to have
AARON                            Our own currency yet, and a few  of don't really keep cash..
GUY                              I charge five dollars per meal,  and I expect customers.
AARON                            I'll tell you what. This cabin iswhat, ten thousand? Twenty?
AARON                            I can't do math in my head, I    never graduated high school.
AARON                            Enoki can do crazy math in her   head, but she isn't here.
AARON                            How about free food for all of usfor the rest of the year,
AARON                            And that'll pay for the food.    C'est bon?
GUY                              ...I'll think about it.
    
OLIVIER                          O-Oh! Excuse me, ma'am. Where didyou come from?
GRAND-MÈRE CORINNE               This greenhouse is still quite   nice, was it moved?
OLIVIER                          Oh.. Well, I was told that it wastransported from inland.
GRAND-MÈRE CORINNE               Well, you see, I once owned this greenhouse, young man.
GRAND-MÈRE CORINNE               I don't see any point in having  ambiguity; I am a ghost.
OLIVIER                          A ghost???
GRAND-MÈRE CORINNE               It seems I am doomed to haunt    this greenhouse forever.
OLIVIER                          My apologize, that seems... it   seems like a terrible fate.
GRAND-MÈRE CORINNE               Would you consider it horrible tospend an eternity here?
OLIVIER                          Now that I think about it.. I    suppose not.
OLIVIER                          It's where I spend most of my    life anyway.
GRAND-MÈRE CORINNE               I see you enjoy taking care of   these plants, son.
GRAND-MÈRE CORINNE               Before I leave, I will remind youof one wisdom.
GRAND-MÈRE CORINNE               Even if your care of these plantsseems meaningless,
GRAND-MÈRE CORINNE               Wonderful things come to the     diligent.
GRAND-MÈRE CORINNE               It was very nice to meet you.    Until next time!
    
OLIVIER                          Bonjour!
GUY                              Oui. J'suppose you're the garden boy?
GUY                              You grow lots of celery, onions, and bell peppers?
OLIVIER                          Well of course!
GUY                              I'll tell you what. You continue to give me fresh supply,
GUY                              And I'll get you free gumbo.
OLIVIER                          What about my wife?
GUY                              She the one with the Wendy's hairor the Wendy's outfit?
OLIVIER                          ...she's the one with the brown  hair.
GUY                              Got it, Dave.
OLIVIER                          ...Olivier. Olivier Landry.
OLIVIER                          Isn't your name Guy?
GUY                              Correct.
OLIVIER                          Don't you go by 'Guy Pizza'?
GUY                              It's more of a joke, but don't   tell no one, you hear?
OLIVIER                          I hear, I hear.
    
ELEANOR                          Bonjour! Comment allez-vous?
GUY                              C'est bon, how are you?
ELEANOR                          This place makes me pretty       hungry, it smells great!
GUY                              Oh yeah?
ELEANOR                          I prefer baking to cooking, but  this is a wonderful kitchen.
GUY                              Yeah, what you make?
ELEANOR                          My favorite thing to make is key lime pie, but sometimes I
ELEANOR                          just need to make a lot of pecan praline. Do you like praline?
GUY                              Like praline?
GUY                              LIKE praline?
GUY                              Yeah, it's pretty good.
GUY                              You get me some praline, and I'llget you free food, how's that?
ELEANOR                          It's a deal!
    
DIANA                            Hey, there! Guy Pizza, is it?
GUY                              Guy Pizza, the one and only.
DIANA                            I can see why, haha. You Italian?
GUY                              Nah, I'm from Donaldsonville.    New name, new life.
DIANA                            And so you chose 'pizza'?
GUY                              People called me 'pizza guy' for ages, and my name's Guy...
GUY                              It was just natural. Plus, it    makes folks hungry.
DIANA                            Yeah, for pizza. Do you make     pizza often?
GUY                              Not often, no.
DIANA                            I guess it's not too late to     change your mind, you know.
GUY                              You got any suggestions?
DIANA                            Guy... Mysterious. That sounds   mysterious.
GUY                              I'm not a magician.
DIANA                            You're also not a pizza.
GUY                              Fair play.
GUY                              I'll take your suggestion into   account, we'll just say that.
    
AARON                            Huh.. No one seems to be home.

 - ESTANQUE DE LOS DESEOS -      NO FUNCIONA PERO SIÉNTETE LIBRE  DE USARLA SI QUIERES
Las rocas que ocupan el camino   ni siquiera te dejan tener una   gran vista del lugar.
Si pudieras subir las rocas,     podrías lanzar una moneda para   pedir un deseo.
Se podría haber planeado mejor   lo del estanque.
- POND OF WISHES -               NE FONCTIONNE PAS MAIS N'HÉSITEZ PAS À L'UTILISER SI VOUS LE VOULEZ
Les rochers qui occupent le chemin ne permettent même pas d'avoir une vue imprenable sur les lieux.
Si vous pouviez escalader les rochers, vous pourriez lancer une pièce pour faire un vœu.
L'étang aurait pu être mieux aménagée.

 - LE MAISON DE LANDRY -

 - DIANA -
No sabría decir si ese es el     nombre de la dueña o de la casa.
- DIANA -
Je ne pourrais pas dire si c'est le nom du propriétaire ou de la maison.

- CASA DE ALGUIEN -
Como puedes ver, por ahora está  deshabitada.
- LA MAISON DE QUELQU'UN -
Comme vous pouvez le voir, pour l'instant il est inhabité.
    
- CASA DE GUY -
La casa de alguien llamado Guy.
- MAISON DE GUY -
La maison d'un certain Guy.

~ JARGINS NOIRS ~

MAPLE                            Oh, hey. ¿Eres Eleanor?
ELEANOR                          ¡Oui! Enchante de faire votre    connaissance.
MAPLE                            Egalement. No querría ofenderte, pero pareces...
MAPLE                            ¿Un poco chapada a la antigua?
ELEANOR                          Oh, estamos acostumbrados a ello.
ELEANOR                          Se siente genial volver a 
ELEANOR                          estar alejada de la gran ciudad. Olvidé los sentimientos
ELEANOR                          que me provocaba el estar        rodeada por los árboles.
MAPLE                            Entiendo. Y tú eres su marido,   ¿j'suppose?
OLIVIER                          Oui, soy Olivier.
ELEANOR                          Aunque es muy reservado, es      alguien muy atento.
ELEANOR                          Le conocí en un jardín y me      enseñó a leer.
OLIVIER                          Ella es muy especial para mí.    Prácticamente salvó mi vida.
MAPLE                            Oh, ¿cómo fue eso?
OLIVIER                          No es algo importante-
ELEANOR                          Por mi madre.
MAPLE                            Ah, puedo hacerme a la idea, je.
ELEANOR                          ¿En serio? Iba a drenar toda su  sangre para un ritual.
MAPLE                            Yo... Hmm, bueno, vale.          Eso... no era lo que esperaba.
MAPLE                            Encantada de conoceros, ¿supongo?
ELEANOR                          ¡Bien sur! Estoy horneando una   tarta para ustedes como 'merci'.
MAPLE                            C'est bon, tan sólo pediría que  no uséis ingredientes raros.
MAPLE                            (¡¿En qué pensaba Scout          invitando a estos raritos?!)
MAPLE                            Oh, hé. Êtes-vous Eleanor?
ELEANOR                          Oui! Enchanté de faire votre connaissance.
MAPLE                            Egalement. Je ne voudrais pas t'offenser, mais tu sembles...
MAPLE                            Un peu démodé?
ELEANOR Oh, nous-autres y sommes habitués.
ELEANOR Ça fait du bien d'être à nouveau loin de la grande ville. J'ai oublié les sensations que me procurait le fait d'être entouré d'arbres.
MAPLE                            Je comprends. Et vous êtes son mari, j'imagine?
OLIVIER Oui, c'est Olivier.
ELEANOR Bien qu'il soit très réservé, c'est quelqu'un de très attentionné.
ELEANOR Je l'ai rencontré dans un jardin et il m'a appris à lire.
OLIVIER Elle est très spéciale pour moi. Cela m'a pratiquement sauvé la vie.
MAPLE                            Oh, comment c'était?
OLIVIER Ce n'est pas quelque chose d'important-
ELEANOR Pour ma mère.
MAPLE                            Ah, je peux m'habituer à l'idée, hé.
ELEANOR Vraiment? Il allait drainer tout son sang pour un rituel.
MAPLE                            Je... Hmm, eh bien, d'accord. Ce... n'était pas ce à quoi je m'attendais.
MAPLE                            Ravi de vous rencontrer, je suppose?
ELEANOR Bon sud! Je prépare un gâteau pour toi en guise de "merci".
MAPLE                            C'est bon, je te demanderais juste de ne pas utiliser d'ingrédients bizarres.
MAPLE                            (A quoi pensait Scout en invitant ces cinglés?!)

ENOKI                            ¡Sed bienvenue! ¡Je suis Enoki!  Ravie de vous autres rencontrer.
ELEANOR                          ¡Bonjour! Enchanté de faire votre connaissance.
OLIVIER                          ¡Bonjour!
ELEANOR                          Soy Eleanor, y éste es mi        marido Olivier.
ENOKI                            ¡Tienes un vestido precioso!     ¿Dónde lo has comprado?
ELEANOR                          ¡Oh! Lo hice yo misma. ¡También  me gusta mucho el tuyo!
ENOKI                            ¡Pues te quedó de maravilla!
ENOKI                            Creo que tenemos la misma altura,¡podríamos hacer cambios!
OLIVIER                          Scout dijo que pertenecías a la  realeza.
ENOKI                            ¡Oh, sí! Este es nuestro pequeño reino, pero no somos déspotas.
ENOKI                            Soy la reina más tranquila y     amigable que llegarás a conocer.
ENOKI                            ¿Queréis convertiros en duque y  duquesa de nuestro reino?
ELEANOR                          Yo... no, gracias. Ni siquiera sélo que esos títulos significan.
OLIVIER                          Merci, en tout cas.
ENOKI                            ¡Bien sur! ¡N'importe quand!
ENOKI                            Soyez les bienvenus! Je m'appelle Enoki! Ravie de vous autres rencontrer.
ELEANOR                          Bonjour! Enchanté de faire votre connaissance.
OLIVIER                          Bonjour!
ELEANOR                          Je suis Eleanor, et voici mon mari Olivier.
ENOKI                            Tu as une belle robe! Où l'as-tu acheté?
ELEANOR                          Ah! Je l'ai fait moi-même. J'aime beaucoup la vôtre aussi!
ENOKI                            Eh bien, c'était merveilleux!
ENOKI                            Je pense qu'on a la même taille, on pourrait faire des changements!
OLIVIER                          Scout a dit que vous faisiez partie de la royauté.
ENOKI                            Ah oui! C'est notre petit royaume, mais nous-autres ne sommes pas des despotes.
ENOKI                            Je suis la reine la plus calme et la plus amicale que vous rencontrerez jamais.
ENOKI                            Voulez-vous devenir le duc et la duchesse de notre royaume?
ELEANOR                          Je... non, merci. Je ne sais même pas ce que mean ces titres.
OLIVIER                          Merci, en tout cas.
ENOKI                            Bon sud! N'importe quand!

AARON                            ¡Bienvenu! ¿Olivier y Eleanor,   asumo?
ELEANOR                          ¡Oui oui!
OLIVIER                          ¿Es usted el 'rey' de esta isla?
AARON                            ¿Scout te dijo eso? Supongo que  podría decir que sí lo soy.
AARON                            Nunca me gradué en el instituto, así que no estoy hecho para otra
AARON                            cosa que no sea el trabajo como  este, pero no quería pasar la
AARON                            vida en una fábrica. Mi esposa, Enoki, y yo, tuvimos la idea de
AARON                            adquirir tierras para vivir a    nuestra bola. Lo de la 'realeza' 
AARON                            fue idea suya. Estaba tan mona   cuando lo pidió que dije que sí.
AARON                            Ella seguramente os haya ofrecidoroles aristocráticos también.
OLIVIER                          Oh, Aaron, ¿no es así? Gracias   por despejar el área para el
OLIVIER                          invernadero. Ahora podré         compartir lo que cultive ahí.
ELEANOR                          ¡Y me encanta esta cabaña!       Me recuerda a mi hogar natal.
ELEANOR                          Vee y yo estábamos emocionados   con la idea de ver la isla.
AARON                            ¡Y a nosotros nos hace felices   que hayáis decidido venir aquí!
AARON                            Si mi hermana pequeña os hace    pasar un mal rato...
AARON                            Os prometo que ella es así y     no lo hace a propósito.
AARON                            Podéis pasaros por la noche para cenar algo todos juntos.
OLIVIER                          Encore une fois, je vous remerciesincerement.
AARON                            Ahora somos una familia, estáis  invitados a venir cuando queráis
AARON                            Bienvenue! Olivier et Eleanor, je suppose?
ELEANOR Oui oui!
OLIVIER                          Êtes-vous le 'roi' de cette île?
AARON                            Est-ce que Scout vous l'a dit? Je suppose que je pourrais dire oui je le suis.
AARON                            Je n'ai jamais terminé mes études secondaires, donc je ne suis pas fait pour autre chose que ce genre de travail, mais je ne voulais pas passer ma vie dans une usine. Ma femme, Enoki, et moi avons eu l'idée d'acquérir un terrain pour vivre par nous-mêmes. Le truc de la "royauté" était son idée. Elle était si mignonne quand elle a demandé que j'ai dit oui.
AARON                            Elle vous a sûrement offert aussi des rôles aristocratiques.
OLIVIER                          Oh, Aaron, n'est-ce pas? Merci d'avoir dégagé la zone pour la serre. Maintenant, je peux partager ce que j'y cultive.
ELEANOR                          Et j'adore cette cabane! Cela me rappelle ma maison natale.
ELEANOR                          Vee et moi étions ravis de voir l'île.
AARON                            Et nous-autres sommes heureux que vous ayez décidé de venir ici!
AARON                            Si ma petite soeur te donne du fil à retordre...
AARON                            Je te promets qu'elle est comme ça et qu'elle ne le fait pas exprès.
AARON                            Vous pouvez passer ce soir pour dîner ensemble.
OLIVIER                          Encore une fois, je vous remercie sincèrement.
AARON                            Nous sommes une famille maintenant, tu es invité à venir quand tu veux

SCOUT                            ¡Hola a todos! Soy Scout, ¿nos   conocemos de internet?
OLIVIER                          ¡Ah! Enchanté de faire votre     connaissance.
ELEANOR                          Oh... Pero al ver tu foto de     internet pensé que tú eras...
SCOUT                            ¿Que yo era qué?
ELEANOR                          Pensé que eras un esqueleto.
SCOUT                            Oh, esa sólo es una foto de un   personaje que me gusta.
SCOUT                            Es un esqueleto de un cómic      llamado Seemore.
SCOUT                            Tiene poderes mágicos, tal vez   pueda prestarte el cómic.
SCOUT                            Te aseguro que es muy divertido  e interesante.
ELEANOR                          ¿Qué es un cómic?
SCOUT                            Yo... Nunca pensé que tendría    que responder a una pregunta
SCOUT                            como esa. Son como los libros    pero tienen imágenes y-
ELEANOR                          ¡Eso suena genial!
OLIVIER                          Eleanor se crió en una secta,    por lo que no sabe mucho del
OLIVIER                          mundo exterior. Esa es una de    las razones por las qué quisimos
OLIVIER                          mudarnos aquí, para descansar un poco de su extensa familia.        
SCOUT                            Oh. Bueno, la hostia. Os doy la  bienvenida a la isla, supongo.
SCOUT                            La reina Enoki tiene mi último   número de Time Raiders,
SCOUT                            pero cuando termine de leerlo,   te lo dejaré para que lo veas.
ELEANOR                          ¡¡Merci!!
SCOUT                            Salut tout le monde! Je suis un scout, nous-autres connaissons-nous sur Internet?
OLIVIER                          Ah! Enchante de faire votre connaissance.
ELEANOR                          Oh... Mais quand j'ai vu ta photo sur internet j'ai cru que tu étais...
SCOUT                            J'étais quoi?
ELEANOR                          Je pensais que tu étais un squelette.
SCOUT                            Oh, c'est juste une photo d'un personnage que j'aime bien.
SCOUT                            est un squelette d'une bande dessinée appelée Seemore.
SCOUT                            A des pouvoirs magiques, je peux peut-être vous prêter la bande dessinée.
SCOUT                            Je vous assure que c'est très amusant et intéressant.
ELEANOR                          Qu'est-ce qu'une bande dessinée?
SCOUT                            Je... Je n'aurais jamais pensé devoir répondre à une telle question. Ils sont comme des livres mais ils ont des images et-
ELEANOR                          Ça sonne bien!
OLIVIER                          Eleanor a grandi dans une secte, elle ne connaît donc pas grand-chose au monde extérieur. C'est l'une des raisons pour lesquelles nous-autres voulions déménager ici, pour avoir une petite pause de sa famille élargie.
SCOUT                            Ah. Eh bien, l'enfer. Je vous souhaite la bienvenu sur l'île, je suppose.
SCOUT                            Reine Enoki a mon dernier numéro de Time Raiders, mais quand j'aurai fini de le lire, je vous laisserai le regarder.
ELEANOR                          Merci!

OLIVIER                          Eleanor, ¿por qué encendiste la  cocina? ¿no vamos a cenar con
OLIVIER                          los Tremblay esta noche?
ELEANOR                          Oh, claro, pero no pude evitarlo.
ELEANOR                          No he visto algo así desde que   era muy pequeña.
ELEANOR                          Así que quería probar a hacerme  unas tostadas.
OLIVIER                          ¿Qué opinas de este lugar?
OLIVIER                          No hay muchas personas, ¿no vas  a sentirte un poco sola?
ELEANOR                          ¿Y tú? ¿Crees que vas a sentirte muy solo aquí?
OLIVIER                          Me gustaría que mi abuelo pudiesevernos ahora mismo.
OLIVIER                          Creo que él estaría muy          orgulloso de ti.
ELEANOR                          Puede que nos vea desde el cielo junto a mi madre.
ELEANOR                          Quizá ella ha cambiado allí y    ahora piense bien de ti.
OLIVIER                          Supongo que no lo podremos saber pero no estoy solo ahora.
OLIVIER                          No he sentido soledad desde que  tú estás conmigo.
ELEANOR                          Vee, espero que nunca dejemos de sentirnos así.
ELEANOR                          He visto cómo se volvieron mis   padres y siento que me hago
ELEANOR                          mayor. Sé que una vez tengamos   a nuestros hijos...
OLIVIER                          ¿Cómo está tu hermana?
ELEANOR                          Está siempre agotada. Bromea     sobre sus canas, pero creo 
ELEANOR                          que le gusta tener el pelo gris. Es diferente a los demás.
ELEANOR                          Ella estaba molesta por cosas    que carecen de sentido.
OLIVIER                          ¿Y si nos pasa lo mismo?. Veamos qué nos depara el futuro.
ELEANOR                          Será extraño tener amigas casada sa nuestra edad. ¿No crees que
ELEANOR                          Diana podría ponerse celosa?
OLIVIER                          Creo que ella se lo pasará bien  aquí. S'il te plait detends-toi!
ELEANOR                          Je suppose que tu as raison, Vee.
OLIVIER                          Eleanor, pourquoi as-tu allumé la cuisinière? N'allons-nous pas dîner avec les Tremblay ce soir?
ELEANOR                          Oh, bien sûr, mais je n'ai pas pu m'en empêcher.
ELEANOR                          Je n'ai rien vu de tel depuis que je suis toute petite.
ELEANOR                          Alors j'ai voulu essayer de me faire des toasts.
OLIVIER                          Que penses-tu de cet endroit?
OLIVIER                          Il n'y a pas beaucoup de monde, tu ne vas pas te sentir un peu seul?
ELEANOR                          Et toi? Pense-tu que tu vas te sentir très seul ici?
OLIVIER                          J'aimerais que mon grand-père puisse nous-autres voir en ce moment.
OLIVIER                          Je pense qu'il serait très fier de toi.
ELEANOR                          Je peux voir le ciel avec ma mère.
ELEANOR                          Peut-être qu'elle a changé là-bas et pense bien de toi maintenant.
OLIVIER                          Je suppose que nous-autres ne pourrons pas le dire mais je ne suis pas seul en ce moment.
OLIVIER                          Je ne me sens plus seul depuis que tu es avec moi.
ELEANOR                          Vee, j'espère que nous-autres n'arrêterons jamais de ressentir cela.
ELEANOR                          J'ai vu comment mes parents sont devenus et j'ai l'impression de vieillir. Je sais qu'une fois que nous-autres aurons nos enfants...
OLIVIER                          Comment va ta sœur?
ELEANOR                          Elle est toujours épuisée. Elle plaisante sur ses cheveux gris, mais je pense qu'il aime avoir des cheveux gris. Elle est différente des autres.
ELEANOR                          Elle était contrariée par des choses qui n'ont aucun sens.
OLIVIER                          Et s'il nous-autres arrivait la même chose? Voyons ce que l'avenir nous-autres réserve.
ELEANOR                          Ce sera étrange d'avoir des amis mariés à notre âge. Ne penses tu pas
ELEANOR                          Diana pourrait-elle être jalouse?
OLIVIER                          Je pense qu'elle va s'amuser ici. S'il te plait relax!
ELEANOR                          Je suppose que c'est ta raison, Vee.

DIANA                            Aw, ¡genial! Me encanta este     sitio, es muy acogedor.
DIANA                            Espero que no os importe que     quiera pasar mucho tiempo aquí.
ELEANOR                          ¡Por supuesto que no! Mientras   no te importe ayudarnos a veces. 
OLIVIER                          Recuerda, vivir así significa    que tendremos que trabajar duro.
OLIVIER                          Es probable que tenga que dedicarmucho tiempo a cortar leña, o a
OLIVIER                          trabajar en el jardín regando y  quitando las malas hierbas.
ELEANOR                          ¿No te interesaba trabajar       para el capitán del barco?
DIANA                            Oh, sí. De hecho me pasaré hoy   mismo por el muelle.
DIANA                            ¡Me haré capitana de barco antes de que os deis cuenta de ello!
ELEANOR                          ¡Sé que podrás con todo lo que   te propongas, Diana!
OLIVIER                          Esto no es lo que pensabas que   harías a tus 22, ¿eh?
DIANA                            Bueno, tampoco es que tuviese    muy claro lo que iba a hacer.
DIANA                            Mudarse a una isla es algo       inesperado para todos. ¿No?
OLIVIER                          Yo pensé que pasaría el resto de mi vida trabajando en el jardín.
ELEANOR                          Yo sigo viva y Vee está con      nosotros, no puedo pedir más.
DIANA                            Sí... Espero que las cosas sigan así de bien por mucho tiempo.
DIANA                            Oh super! J'adore cet endroit, c'est très cosy.
DIANA                            J'espère que cela ne te dérange pas que je veuille passer beaucoup de temps ici.
ELEANOR                          Bien sûr que non! Tant que cela ne te dérange pas de nous-autres aider parfois.
OLIVIER                          Rappeles tu, vivre ainsi signifie que nous-autres devons travailler dur.
OLIVIER                          Tu devras probablement passer beaucoup de temps à couper du bois, ou travailler dans le jardin à arroser et désherber.
ELEANOR                          N'étais-tu pas intéressé à travailler pour le capitaine du navire?
DIANA                            Oh oui. En fait, je vais m'arrêter à la jetée aujourd'hui.
DIANA                            Je serai capitaine d'un navire avant que tu ne le saches!
ELEANOR                          Je sais que tu peux faire tout ce que tu veux, Diana!
OLIVIER                          Ce n'est pas ce que tu pensais faire à 22 ans, hein?
DIANA                            Eh bien, ce n'est pas comme si j'étais très claire sur ce que j'allais faire.
DIANA                            Déménager sur une île est quelque chose d'inattendu pour tout le monde. Non?
OLIVIER                          Je pensais passer le reste de ma vie à jardiner.
ELEANOR                          Je suis toujours en vie et Vee est avec nous, je ne peux pas en demander plus.
DIANA                            Oui... J'espère que les choses resteront aussi bonnes pendant longtemps.

MAPLE                            Salut, chicos.
ELEANOR                          ¡Salut, Maple! ¿Quieres un poco  de guiso? Está recién hecho.
MAPLE                            ¡Eso suena muy bien! Claro que   quiero, tu guiso es fantástico.
OLIVIER                          Diana nos ha traído un nuevo     juego de mesa.
OLIVIER                          ¿Podrías avisar a los demás para jugar con nosotros esta noche?
MAPLE                            ¿Y qué hay de mí?                Nah, no pasa nada, haha.
MAPLE                            Hey, um... Siento lo del juego   de mesa de la semana pasada.
ELEANOR                          Está bien, Maple. Todos podríamosenfadarnos con un juego.
MAPLE                            Aunque tu cabaña parece haber    dejado de oler a humo.
ELEANOR                          ¿Has probado el nuevo            gumbo isleño?
MAPLE                            ¿Me preguntáis si me asusta      probarlo? Nah, no mucho.
MAPLE                            Sea como sea, no es nada que el  tabasco extra no pueda arreglar.
MAPLE                            Sé que no os veo demasiado       tiempo pero...
MAPLE                            Quiero daros las gracias por los ingredientes. Sois un cielo.
OLIVIER                          Gracias por tu arduo trabajo.    No tenía todas mis esperanzas
OLIVIER                          puestas en que todo esto de la   isla funcionase tan bien.
OLIVIER                          Es casi como si tuvieras un      amuleto de la buena suerte.
MAPLE                            Sí... De alguna forma, Enoki     consigue todo lo que se propone.
MAPLE                            Es sólo cuestión de tiempo       que algo le salga mal, no logre
MAPLE                            lo que quiere y se le crucen los cables, también te digo.
OLIVIER                          Ya veo. Bueno, si necesitas algo de nosotros sólo debes pedirlo.
MAPLE                            ¡Lo mismo os digo!.
MAPLE                            Bonjour, les gars.
ELEANOR                          Bonjour, Maple! Voulez-vous du ragoût? C'est fraîchement préparé.
MAPLE                            Ça sonne bien! Bien sûr que je veux, votre ragoût est fantastique.
OLIVIER                          Diana nous-autres propose un nouveau jeu de société.
OLIVIER                          Pourriez-vous dire aux autres de jouer avec nous-autres ce soir?
MAPLE                            Et moi? Non, rien ne se passe, haha.
MAPLE                            Hey, euh... Désolé pour le jeu de plateau de la semaine dernière.
ELEANOR                          C'est bon, Maple. Nous pourrions tous nous-autres fâcher à un match.
MAPLE                            Bien que votre cabine semble avoir cessé de sentir la fumée.
ELEANOR                          Avez-vous essayé le nouveau gumbo des îles?
MAPLE                            Vous me demandez si j'ai peur de l'essayer? Nan, pas grand-chose.
MAPLE                            Quoi qu'il en soit, il n'y a rien que Tabasco supplémentaire ne puisse réparer.
MAPLE                            Je sais que je ne te vois pas trop mais...
MAPLE                            Je tiens à vous remercier pour les ingrédients. Vous êtes un ciel.
OLIVIER                          Merci pour votre travail acharné. Je n'avais pas tous mes espoirs que toute cette histoire d'île fonctionnait si bien.
OLIVIER                          C'est presque comme si vous aviez un porte-bonheur.
MAPLE                            Oui... D'une manière ou d'une autre, Enoki obtient tout ce qu'il veut.
MAPLE                            Ce n'est qu'une question de temps avant que quelque chose ne tourne mal, il ne réalise pas ce qu'il veut et les fils se croisent, je vous le dis aussi.
OLIVIER                          Je vois. Eh bien, si vous avez besoin de quelque chose de notre part, tout ce que vous avez à faire est de demander.
MAPLE                            Je te dis la même chose!

ENOKI                            ¡¡Salut!! ¿Cómo estáis hoy?
ELEANOR                          ¡Estamos muy bien! ¿Quieres      algo de guiso?
ENOKI                            Mentiría si dijese que alguien   no lo quiso, jeje.
OLIVIER                          ¿Vendrás a jugar esta noche?
ENOKI                            ¡No me lo perdería por nada del  mundo!
ELEANOR                          ¿Has conocido ya al nuevo isleño?
ENOKI                            No le digáis nada a Maple...
ENOKI                            pero creo que su gumbo es mejor  que el suyo.
ENOKI                            Tenéis que prometerme que NO le  diréis a Maple lo que pienso.
ELEANOR                          Mis labios están sellados.
ENOKI                            Oye, ¿tenéis una máquina de      coser por aquí?
ELEANOR                          Oui.
ENOKI                            Dijiste que te hacías tus propiasvestimentas, ¿oui? Tú, eh...
ENOKI                            ¿No te importaría enseñarme a    hacer lo mismo que tú?
ELEANOR                          Pas du tout! Sería un placer     para mí enseñarte lo que sé.
ENOKI                            Salut!! Comment vas-tu aujourd'hui?
ELEANOR                          Nous allons très bien! Voulez-vous du ragoût?
ENOKI                            Je mentirais si je disais que quelqu'un n'en voulait pas, hehe.
OLIVIER                          Tu viens jouer ce soir?
ENOKI                            Je ne manquerais ça pour rien au monde!
ELEANOR                          Avez-vous déjà rencontré le nouvel insulaire?
ENOKI                            Ne dis rien à Maple...
ENOKI                            mais je pense que son gombo est meilleur que le tien.
ENOKI                            Tu dois me promettre de ne PAS dire à Maple ce que je pense.
ELEANOR                          Mes lèvres sont scellées.
ENOKI                            Hé, tu as une machine à coudre par ici?
ELEANOR                          Oui.
ENOKI                            Tu as dit que tu fabriques tes propres vêtements, oui? Tu, euh...
ENOKI                            Ça ne vous dérangerait pas de m'apprendre à faire la même chose que vous?
ELEANOR                          Pas du tout! Il me fera plaisir de vous enseigner ce que je sais.

AARON                            ¡Salut! Escuché algo sobre los   juegos de mesa esta noche.
ELEANOR                          ¡Oui! Nos gustaría organizarlo   fuera debajo de un árbol.
ELEANOR                          Hice una colcha suficientemente  grande para que todos quepan.
AARON                            ¿Será fuera esta vez para que    Maple no la líe de nuevo, no?
OLIVIER                          Oui, jaja.
ELEANOR                          También hemos hecho guiso, por   si te apetece comer algo.
AARON                            Ya me comí lo que quedaba del    gumbo de Maple, ¡pero merci!
AARON                            Hablando de comida. Aunque sea   tímido, Guy es buen chaval.
AARON                            Me emociona que más personas     lleguen a la isla.
OLIVIER                          Poco a poco esto se convierte    en un auténtico pueblo.
AARON                            Sí, estaba pensando lo mismo.
OLIVIER                          ¿Te encuentras bien, Aaron?      Tienes la cara pálida.
AARON                            Sí, Sólo pensaba que Maple y yo  no lo llevamos demasiado bien.
OLIVIER                          ¿A qué te refieres?
AARON                            Ella no quiere mudarse, pero va  a tener que hacerlo.
OLIVIER                          ¿Y por qué no hablas con ella?   ¿No eres el rey o algo así?
AARON                            Podría. Más bien, debería. Pero  es difícil lidiar con ella.
AARON                            No termina de decidirse con eso  que dice de ser independiente,
AARON                            dice serlo pero al siguiente día la tienes como una garrapata.
OLIVIER                          Eso suena como algo que deberías dialogar con ella, no nosotros.
AARON                            La verdad es que tienes toda la  razón del mundo.
AARON                            Bonjour! J'ai entendu parler de jeux de société ce soir.
ELEANOR                          Oui! Nous aimerions l'installer à l'extérieur sous un arbre.
ELEANOR                          J'ai fait une courtepointe assez grande pour que tout le monde puisse s'y glisser.
AARON                            Ça va être dehors cette fois donc Maple ne la bousillera pas encore, n'est-ce pas?
OLIVIER                          Oui, ha ha.
ELEANOR                          Nous avons aussi fait du ragoût, au cas où tu aurais envie de manger quelque chose.
AARON                            J'ai déjà mangé le reste du gombo à Maple, mais merci!
AARON                            Parlant de nourriture. Bien qu'il soit timide, Guy est un bon garçon.
AARON                            Je suis ravi que plus de gens viennent sur l'île.
OLIVIER                          Petit à petit cela devient un vrai village.
AARON                            Ouais, je pensais la même chose.
OLIVIER                          Ça va, Aaron? Vous avez un visage pâle.
AARON                            Ouais, je pensais juste que Maple et moi ne nous-autres entendions pas très bien.
OLIVIER                          Que veux-tu dire?
AARON                            Elle ne veut pas bouger, mais elle va devoir le faire.
OLIVIER                          Pourquoi ne lui parles-tu pas? N'êtes-vous pas le roi ou quoi?
AARON                            Pourrait. Au contraire, il devrait. Mais c'est difficile de faire affaire avec elle.
AARON                            Il n'a pas fini de décider avec ce qu'il dit à propos d'être indépendant, il dit qu'il l'est mais le lendemain tu l'as comme une tique.
OLIVIER                          Cela ressemble à quelque chose dont vous devriez discuter avec elle, pas avec nous.
AARON                            La vérité est que vous avez absolument raison.

SCOUT                            ¡Hola a todos! ¡Scout ha llegado!
ELEANOR                          ¡Salut! ¿Quieres guiso?
SCOUT                            Merci, pero comí hace... Espera. ¿Cuándo fue la última vez?  
SCOUT                            Diantes, no he comido en todo el día. ¡Claro que quiero guiso!
ELEANOR                          Jeje, no hay problema, sírvete   lo que quieras.
SCOUT                            ¿Habéis visto el reporte de      Scout TV esta mañana?
ELEANOR                          Oh, no tenemos una televisión.
SCOUT                            Es verdad... Lo lamento, olvidad lo que he dicho antes.
SCOUT                            De todos modos mi transmisión    fue pirateada.
OLIVIER                          ¿Pirateada? ¿Por quién?
SCOUT                            Ni idea. Los Tremblay no parecen muy preocupados de todas formas.
ELEANOR                          ¿Vas a venir a jugar con nosotrosesta noche?
SCOUT                            Trataré de hacerlo, todavía      tengo trabajo por delante.
SCOUT                            Luego os digo si me es posible.
OLIVIER                          Sin problema, te guardaremos un  asiento por si vienes.
SCOUT                            ¡Merci!
ELEANOR                          ¡De rien!
SCOUT                            Salut tout le monde! Scout est arrivé!
ELEANOR                          Bonjour! Voulez-vous du ragoût?
SCOUT                            Merci, mais j'ai mangé il y a... Attendez. Quand était la dernière fois?
SCOUT                            Merde, je n'ai pas mangé de la journée. Bien sûr, je veux du ragoût!
ELEANOR                          Hehe, pas de problème, servez-vous de ce que vous voulez.
SCOUT                            Avez-vous vu le reportage de Scout TV ce matin?
ELEANOR                          Oh, nous-autres n'avons pas de télévision.
SCOUT                            C'est vrai... Je suis désolé, oublie ce que j'ai dit avant.
SCOUT                            Ma transmission a été piratée de toute façon.
OLIVIER                          piraté? Par qui?
SCOUT                            Aucune idée. Les Tremblay ne semblent pas trop inquiets de toute façon.
ELEANOR                          Tu viens jouer avec nous-autres ce soir?
SCOUT                            Je vais essayer de le faire, j'ai still du travail devant moi.
SCOUT                            Alors je te dirai si c'est possible.
OLIVIER                          Pas de problème, on vous garde une place si vous venez.
SCOUT                            Merci!
ELEANOR                          De rien!

OLIVIER                          Así que tu cumpleaños es en una  semana...
ELEANOR                          ¿Oui?
OLIVIER                          Quisiera darte una sorpresa, perono quiero decepcionarte con-
ELEANOR                          ...
OLIVIER                          ... ¿Quieres que te dé una       sorpresa?
OLIVIER                          ...
OLIVIER                          ¿Todavía piensas en la ceremonia?
ELEANOR                          Esa fue una noche que no podré   olvidar jamás.
ELEANOR                          No sabría decirte si me sentiría bien o mal con una sorpresa.
ELEANOR                          Me has dado montones de regalos  de cumpleaños toda la vida.
OLIVIER                          Pero no te quejarías si te comprouna nueva máquina de coser.
ELEANOR                          ...
OLIVIER                          No te confirmo que sea eso lo quevaya a regalarte pero...
ELEANOR                          ¿No tienes algunas ciruelas      pasas? Necesito comenzar
ELEANOR                          a enlatarlas para el invierno.
OLIVIER                          Vale, vale, es sólo que-...      Bueno, no importa.
OLIVIER                          Alors ton anniversaire c'est dans une semaine...
ELEANOR                          Oui?
OLIVIER                          J'aimerais te surprendre, mais je ne veux pas te décevoir avec-
ELEANOR                          ...
OLIVIER                          ... Tu veux que je te surprenne?
OLIVIER                          ...
OLIVIER                          Pense-tu encore à la cérémonie?
ELEANOR                          C'était une nuit que je n'oublierai jamais.
ELEANOR                          Je ne pourrais pas te dire si je me sentirais bien ou mal d'avoir une surprise.
ELEANOR                          Tu m'as offert plein de cadeaux d'anniversaire toute ma vie.
OLIVIER                          Mais tu ne te plaindrais pas si je m'achetais une nouvelle machine à coudre.
ELEANOR                          ...
OLIVIER                          Je ne peux pas confirmer que c'est ce que je vais te donner mais...
ELEANOR                          Tu n'as pas de pruneaux? je dois commencer
ELEANOR                          pour les mettre en conserve pour l'hiver.
OLIVIER                          D'accord, d'accord, c'est juste... Eh bien, tant pis.

DIANA                            Chicos, tenemos que hablar.
OLIVIER                          ¿Qué ocurre?
DIANA                            Alguien ha pirateado el canal    de Scout esta mañana.
DIANA                            Creo que ha sido un Mons d'Plonj,es una amenaza para la isla.
ELEANOR                          O-Oh.. Oh no.. No tendrá nada    que ver con las brujas, ¿no?
ELEANOR                          Vee, ¿han dado con nosotros?
DIANA                            No, sólo parecía un imbécil.     ¿Parece que Maple lo conoce?
DIANA                            Los Tremblay no están            preocupados.
ELEANOR                          Oh... Menos mal...
DIANA                            ¿Aunque conocéis a ese tal César?¿El chico del norte?
DIANA                            Aunque parece sospechoso, Enoki  confía en él. Tiene una
DIANA                            tienda o algo así. Y el otro     chico, Guy, cocina muy bien.
OLIVIER                          Hey, El, cálmate, parece que     estés al borde de un ataque.
ELEANOR                          Lo siento... Lo siento...
DIANA                            Oye, Eleanor, todo va a salir    bien. ¿Te vienes conmigo?
DIANA                            Podremos relajarnos y comer      snacks importados.
DIANA                            Sí, eso suena divertido.         Merci.
DIANA                            Les gars, nous-autres devons parler.
OLIVIER Qu'y a-t-il?
DIANA                            Quelqu'un a piraté la chaîne de Scout ce matin.
DIANA                            Je pense que c'était un Mons d'Plonj, il est une menace pour l'île.
ELEANOR O-Oh.. Oh non.. Ça n'aura rien à voir avec les sorcières, n'est-ce pas?
ELEANOR Vee, nous-autres ont-ils trouvés?
DIANA                            Non, il avait juste l'air d'un abruti. Est-ce que Maple semble le connaître?
DIANA                            Les Tremblay ne sont pas inquiets.
ELEANOR Oh... Dieu merci...
DIANA                            Même si tu connais ce César, le garçon du nord?
DIANA                            Bien qu'il semble méfiant, Enoki lui fait confiance. Il a un magasin ou quelque chose comme ça. Et l'autre garçon, Guy, cuisine très bien.
OLIVIER Salut, El, calme-toi, tu as l'air d'être au bord de la crise.
ELEANOR Je suis désolé... je suis désolé...
DIANA                            Hé, Eleanor, ça va aller. Vous venez avec moi?
DIANA                            Nous pouvons nous-autres détendre et manger des collations importées.
DIANA                            Ouais, ça a l'air amusant. Merci.

ELEANOR                          ¡Bonjour! Tú debes ser Guy.
GUY                              Oui. Soy Guy. Guy Pizza.
ELEANOR                          ¿Guy... Pizza?
GUY                              El nombre era más divertido      cuando trabajaba en la pizzería.
OLIVIER                          Bueno, en cualquier caso,        ¡eres bienvenido a la isla!
GUY                              Encantado de conoceros. Aún debo terminar de preparar mis cosas.
GUY                              Siempre he querido una cocina de tamaño completo y voy a hacer
GUY                              buen uso de ella, ya verás.
ELEANOR                          Vamos a jugar a un juego de mesa esta noche.
ELEANOR                          ¿Quieres unirte a nosotros?
GUY                              Me encantaría, pero ahora mismo  estoy emocionado por la cocina.
ELEANOR                          Ya veo... Espero que te          diviertas con tu cocina.
GUY                              Oh, lo haré. Lo haré.
ELEANOR                          Bonjour! Vous devez être Guy.
GUY                              Oui. Je suis un gars. Guy Pizza.
ELEANOR                          Guy... Des pizzas?
GUY                              Le nom était plus drôle quand il travaillait à la pizzeria.
OLIVIER                          Eh bien, en tout cas, vous êtes les bienvenus sur l'île!
GUY                              Ravi de vous rencontrer. Je dois still finir de préparer mes affaires.
GUY                              J'ai toujours voulu une cuisine pleine grandeur et je vais en faire bon usage, vous verrez.
ELEANOR                          On va jouer à un jeu de société ce soir.
ELEANOR                          Vous souhaitez nous-autres rejoindre?
GUY                              J'adorerais, mais en ce moment je suis excité par la cuisine.
ELEANOR                          Je vois... J'espère que tu t'amuses bien avec ta cuisine.
GUY                              Oh, je le ferai. Je le ferai.

ELEANOR                          ¿Qué está ocurriendo fuera?
AARON                            No lo sé, pero sígueme, vamos al búnker de Scout a esperar
AARON                            hasta que las cosas se calmen.
AARON                            ¿Dónde está Diana?
OLIVIER                          Salió a navegar con Guy y        no volverá hasta más tarde.
AARON                            Gracias a Dios. Seguidme, vamos  a salir de aquí.
ELEANOR                          Que se passe-t-il dehors?
AARON                            Je ne sais pas, mais suivez-moi, nous-autres allons au bunker de Scout et attendons que les choses se calment.
AARON                            Où est Diana?
OLIVIER                          Elle est partie naviguer avec Guy et ne reviendra que plus tard.
AARON                            Dieu merci. Suivez-moi, sortons d'ici.

    Esta es la biblioteca de     Eleanor.

    La puerta está cerrada.
    No deberías fisgonear en     los lugares de otras personas.

    C'est la bibliothèque d'Eleanor.

    La porte est fermée.
    Vous ne devriez pas fouiner chez les autres.
    
MAPLE                            ¡Hey! ¿Eres Diana?
DIANA                            ¡Hiya! ¡Al fin! ¡Otro pelirrojo!
MAPLE                            Oh, mi pelo no es rojo, más bien es rubio miel.
MAPLE                            Soy una elfa, así que a veces se me pone algo anaranjado.
DIANA                            Oh, ¿lo eres? Entonces...
MAPLE                            ¿Vas a preguntar por qué mis     orejas son redondeadas?
DIANA                            Me daba cosa preguntar por si te hacía sentir incómoda.
MAPLE                            Está bien. Fueron cortadas       cuando era un bebé.
MAPLE                            Mi nombre es Maple, por cierto.  Maple Tremblay.
DIANA                            ¡Heureux de te rencontrer!
DIANA                            ¡Estas cabañas son confortables! ¿Las hace tu hermano mayor?
MAPLE                            Mayormente sí. Yo a veces salgo  a buscar gemas en las cuevas.
MAPLE                            Ganamos lo suficiente como para  vivir bien aquí.
DIANA                            ¿Vives en la casa rodante?
MAPLE                            Sí. Suelo quedarme en el sofá.
DIANA                            ¿Y no quieres una cabaña? Una de ellas parece estar vacía.
MAPLE                            Verás, Aaron y Enoki quieren     hacer un castillo.
MAPLE                            Así que pienso quedarme esta     casa cuando eso ocurra.
DIANA                            Así que... Este lugar, ¿es un    país de verdad?
MAPLE                            Si actuamos como que lo es,      entonces lo es. ¿No?
DIANA                            ¿Es así de fácil crear un país?
MAPLE                            Hasta que tengamos que librar unaguerra. Un placer conocerte.
DIANA                            Ehm, sí, ¡también es un placer   conocerte!
MAPLE                            Hé! Vous êtes Diane?
DIANA                            Salut! À la fin! Encore une rousse!
MAPLE                            Oh, mes cheveux ne sont pas roux, c'est plutôt blond miel.
MAPLE                            Je suis un elfe, donc parfois je reçois un peu d'orange.
DIANA                            Oh, c'est ça? Ensuite...
MAPLE                            Allez-vous me demander pourquoi mes oreilles sont arrondies?
DIANA                            Ça ne me dérangeait pas de demander au cas où ça te mettrait mal à l'aise.
MAPLE                            D'accord. Ils ont été coupés quand il était bébé.
MAPLE                            Je m'appelle Maple, au fait. Maple Tremblay.
DIANA                            Heureux de te revoir!
DIANA                            Ces cabines sont confortables! Est-ce que ton frère aîné en fait?
MAPLE                            Surtout oui. Je sors parfois chercher des pierres précieuses dans les grottes.
MAPLE                            Nous gagnons assez pour bien vivre ici.
DIANA                            Vivez-vous dans la caravane?
MAPLE                            Oui, je reste habituellement sur le canapé.
DIANA                            Et tu ne veux pas de cabane? Un d'eux semble vide.
MAPLE                            Vous voyez, Aaron et Enoki veulent faire un château.
MAPLE                            Donc, je prévois de garder cette maison quand cela arrivera.
DIANA                            Alors... Cet endroit, est-ce un vrai pays?
MAPLE                            Si nous-autres agissons comme il est, alors il est. Non?
DIANA                            Est-ce si aisé de créer un pays?
MAPLE                            Jusqu'à ce que nous-autres ayons à faire la guerre. Un plaisir de te connaitre.
DIANA                            Ehm, oui, ravie de vous rencontrer aussi!
aisé

ENOKI                            ¡Hey! ¿Eres Diana?               ¡Soy Enoki Tremblay!
DIANA                            ¡Enchante de faire votre         connaissance!
ENOKI                            ¿Estás sintiéndote cómoda aquí?
DIANA                            Es una locura, no sabría decirte si estoy soñando o no.
DIANA                            Todo es como demasiado increíble como para ser real.
ENOKI                            Soy una chica con suerte, cuando quiero que algo ocurra...
ENOKI                            Las cosas suelen salir bien, y   quería que esto funcionase.
ENOKI                            ¿Escuché que sueles salir con el capitán Nicholas?
DIANA                            ¡Sí! Está buscando a alguien que se haga cargo de esta área.
DIANA                            Eventualmente, conduciré el      barco por todo el Superieur.
ENOKI                            ¡Suena divertido! Llévanos de    paseo en algún momento.
ENOKI                            Si necesitas cualquier cosa no   tienes más que decirlo.
DIANA                            ¡D'accord!
ENOKI                            Hé! Vous êtes Diane? Je suis Enoki Tremblay!
DIANA                            Enchanté de faire ta connaissance!
ENOKI                            Vous sentez bien ici?
DIANA                            C'est fou, je ne pourrais pas te dire si je rêve ou non.
DIANA                            C'est trop incroyable pour être réel.
ENOKI                            Je suis une fille chanceuse, quand je veux que quelque chose se passe...
ENOKI                            Les choses marchent généralement bien, et je voulais que ça marche.
ENOKI                            J'ai entendu dire que tu sortais souvent avec le Capitaine Nicholas?
DIANA                            Oui! Il cherche quelqu'un pour prendre en charge ce domaine.
DIANA                            Finalement, je conduirai le navire partout dans le Supérieur.
ENOKI                            Ça a l'air amusant! Emmenez-nous faire un tour de temps en temps.
ENOKI                            Si vous avez besoin de quoi que ce soit, vous n'avez qu'à le dire.
DIANA                            D'accord!

DIANA                            ¡Bienvenue! Eres Tremblay, ¿oui?
AARON                            ¡Bienvenu! ¿Cómo llevas la       cabaña? ¿todo bien?
DIANA                            ¡Es genial! Demasiado genial     como para ser real.
DIANA                            Hoy tendré mi primera instrucciónconduciendo el barco.
DIANA                            ¿Conoces al capitán Nicholas?
AARON                            La verdad es que pasé la mayoría del tiempo cortando leña.
AARON                            Pero parece ser buena persona porlo que tengo entendido.
AARON                            No me quedaré mucho, sólo me     pasé para ver cómo estabas.
AARON                            Hazme saber si necesitas algo,   ¿está bien?
DIANA                            ¡Por supuesto! ¡Muchas gracias!
DIANA                            Bienvenue! Vous êtes Tremblay, oui?
AARON                            Bienvenu! Comment gérez-vous la cabine? tout va bien?
DIANA                            C'est super! Trop cool pour être vrai.
DIANA                            Aujourd'hui, j'aurai ma première instruction de conduite du bateau.
DIANA                            Connaissez-vous le capitaine Nicholas?
AARON                            La vérité, c'est que j'ai passé la plupart de mon temps à couper du bois.
AARON                            Mais il semble être une bonne personne d'après ce que j'ai compris.
AARON                            Je ne resterai pas longtemps, je suis juste passé voir comment tu allais.
AARON                            Dis-moi si tu as besoin de quoi que ce soit, d'accord?
DIANA                            Bien sûr! Merci beaucoup!

SCOUT                            ¡Hey! Soy yo, Scout. Sólo quería presentarme.
DIANA                            ¡Ah, encantada! Sigo sin estar   segura de si esto es real...
DIANA                            Me alegra no haber... Bueno...   Sido asesinada o algo así.
SCOUT                            Admito que yo también llevo poco tiempo aquí.
SCOUT                            Me mudé aquí desde una isla que  no está demasiado lejos.
SCOUT                            Pero entonces conocí a los       Tremblay y decidí unirme.
SCOUT                            No fué tan fácil abrir un nuevo  búnker, aunque valió la
SCOUT                            pena. Me siento a gusto aquí.
DIANA                            Bueno, parece que te va bien.    ¿Eres científico?
SCOUT                            Sí, es curioso. Porque además    una compañía me envió aquí
SCOUT                            para hacer algunos experimentos  en la isla. No sé por qué.
DIANA                            ¿Y encontraste lo que buscabas?
SCOUT                            He creado este dispositivo que   hace búnkers rápidamente.
SCOUT                            No sé para qué más lo voy a usar,pero tiene potencial.
DIANA                            Hey, si te apetece, ¿me harías   un búnker en algún momento?
SCOUT                            ¡Claro, me encantaría!
SCOUT                            Hé! C'est moi, scout. Je voulais juste me présenter.
DIANA                            Oh, ravie! Je ne sais toujours pas si c'est réel...
DIANA                            Je suis contente de ne pas avoir... Eh bien... été tuée ou quelque chose comme ça.
SCOUT                            J'avoue que je ne suis ici que depuis peu de temps aussi.
SCOUT                            J'ai déménagé ici d'une île qui n'est pas trop loin.
SCOUT                            Mais ensuite j'ai rencontré les Tremblay et j'ai décidé de me joindre.
SCOUT                            Ce n'était pas si aisé d'ouvrir un nouveau bunker, mais ça valait le coup. Je me sens bien ici.
DIANA                            Eh bien, tu sembles aller bien. Êtes-vous un scientifique?
SCOUT                            Oui, c'est drôle. Parce qu'une entreprise m'a aussi envoyé ici pour faire des expériences sur l'île. Je ne sais pas pourquoi.
DIANA                            Et avez-vous trouvé ce que vous cherchiez?
SCOUT                            J'ai créé cet appareil qui fait des bunkers rapidement.
SCOUT                            Je ne sais pas pour quoi d'autre je vais l'utiliser, mais il a du potentiel.
DIANA                            Hé, si tu en as envie, pourrais-tu me construire un bunker un jour?
SCOUT                            Bien sûr, j'adorerais!

DIANA                            ¡Hey, Vee! ¡Me alegra verte en mi/nueva cabaña/!
OLIVIER                          Sólo te tomó alrededor de un     día hacerla lucir como
OLIVIER                          tu viejo hogar, ¿eh?
DIANA                            Si todo va bien, esta cabaña     será como mi antigua casa.
OLIVIER                          Todo dependerá de si podemos     confiar en estas personas.
OLIVIER                          Tienes algo para defenderte si   las cosas se tuercen, ¿no?
DIANA                            Sí, llevo encima una pistola de  bengalas.
DIANA                            Aunque espero no tener que       utilizarla.
OLIVIER                          Espero que no sea necesario.     Parecen gente agradable.
OLIVIER                          O al menos parece que no tengan  interés en sacrificarnos.
DIANA                            Jeje, ya te digo. Si aparece     alguien de la familia de El,
DIANA                            Llámame inmediatamente, ¿vale?
OLIVIER                          Claro, por supuesto.
DIANA                            Hé, tu vois! Heureux de te voir dans ma /nouvelle cabine/!
OLIVIER                          Il ne tu a fallu qu'une journée pour la faire ressembler à
OLIVIER                          votre ancienne maison, hein?
DIANA                            Si tout va bien, cette cabane sera comme mon ancienne maison.
OLIVIER                          Tout dépendra si nous-autres pouvons faire confiance à ces personnes.
OLIVIER                          Tu as de quoi te défendre si les choses tournent mal, n'est-ce pas?
DIANA                            Oui, je porte une fusée éclairante.
DIANA                            Bien que j'espère ne pas avoir à l'utiliser.
OLIVIER                          J'espère que ce n'est pas nécessaire. Ils ont l'air de gens sympas.
OLIVIER                          Ou du moins ils semblent n'avoir aucun intérêt à nous-autres sacrifier.
DIANA                            Hehe, je te le dis. Si quelqu'un de la famille d'El se présente,
DIANA                            Appelle-moi tout de suite, d'accord?
OLIVIER                          Bien sûr, bien sûr.

ELEANOR                          ¡Se parece a tu antigua          habitación!
DIANA                            Claro, ¿acaso esperabas otra cosade mí? Jeje.
ELEANOR                          Me encanta cómo la has dejado,   es muy acogedora.
ELEANOR                          Avísame si necesitas cualquier   cosa,
ELEANOR                          Decoré mi habitación, y tenemos  otra preparada para la bola
ELEANOR                          de cristal. Aún sigo practicando la invocación.
DIANA                            ¿Y no crees que usar la magia    podría causar que... ehm...
DIANA                            las brujas sepan dónde estás?
ELEANOR                          Me mantengo positiva. Si esto    sale suficientemente bien,
ELEANOR                          podríamos incluso invitarles a   venir. Me encantaría 
ELEANOR                          mostrarles este sitio. Parece    ser un lugar relajante.
DIANA                            No es que hayamos tenido una vidatranquila hasta ahora.
DIANA                            Por cierto, ¿Has hablado ya con  los Tremblay?
DIANA                            Parece que podríamos llevarnos   bien con ellos.
DIANA                            Hay una chica pelirroja y una    pareja de... ¿granjeros?
DIANA                            Esa tal Enoki es mona, ¡pero tú  lo eres aún más!
ELEANOR                          Aw, ¡Merci!
DIANA                            No puedo evitar sentirme un poco inquieta, pero creo que
DIANA                            estaremos bien aquí.
ELEANOR                          Yo pienso lo mismo.
ELEANOR                          Elle ressemble à votre ancienne chambre!
DIANA                            Bien sûr, tu attends autre chose de ma part? Il il.
ELEANOR                          J'adore la façon dont tu l'as laissé, c'est tellement confortable.
ELEANOR                          Faites-moi savoir si tu avez besoin de quoi que ce soit,
ELEANOR                          J'ai décoré ma chambre, et nous-autres en avons une autre prête pour la boule de cristal. Je pratique toujours l'invocation.
DIANA                            Et tu ne penses pas que l'utilisation de la magie pourrait amener... euh... les sorcières à savoir où tu es?
ELEANOR                          Je reste positif. Si tout se passe bien, nous-autres pourrions même les inviter à venir. J'aimerais te montrer ce site. Cela semble être un endroit relaxant.
DIANA                            Ce n'est pas que nous-autres ayons eu une vie tranquille jusqu'ici.
DIANA                            Au fait, avais-tu déjà parlé à Tremblay?
DIANA                            On dirait qu'on pourrait s'entendre avec eux.
DIANA                            Il y a une fille rousse et deux... fermiers?
DIANA                            Cet Enoki est mignon, mais tu l'es encore plus!
ELEANOR                          Ah, merci!
DIANA                            Je ne peux pas m'empêcher de me sentir un peu perturbée, mais je pense que tout ira bien ici.
ELEANOR                          Je pense la même chose.

MAPLE                            ¡Diana! ¡Hey!
DIANA                            ¡Hey, Maple!                     ¿Qué tal, corazón?
MAPLE                            Bien, aunque un poco aburrida.
DIANA                            ¿Viste la transmisión de esta    mañana?
MAPLE                            ¿La que Rufus pirateó? Es un     idiota, estaremos bien.
MAPLE                            Igual ahora piensa que es un     super villano o algo así.
DIANA                            Los chicos así me hacen reír a   carcajadas, en serio. ¡Jajaja!
MAPLE                            Y que lo digas. Pero hazme saber si le ves por ahí.
MAPLE                            El caimán frito es una delicia   durante esta época del año.
DIANA                            Lo haré.
DIANA                            ¿Qué te cuentas?
MAPLE                            ¿Has visto a Scout? Ese pobre    chico se ha pillado por mí.
MAPLE                            Es un chico dulce, pero tendré   que dejarle claro con el
MAPLE                            tiempo que definitivamente       no es mi tipo.
DIANA                            Chica, no envidio tu situación,  jajaa. ¿Cuál es tu tipo?
MAPLE                            Me gustaría alguien alocado y    que me haga sentir emoción.
MAPLE                            Todos los chicos actúan como si  fuera una diosa y todo termina
MAPLE                            siempre igual. Podría hacer una  barbacoa con ellos si quisiera.
DIANA                            Je, tal vez todos te traten así  porque terminas asustándoles.
MAPLE                            Igual todo se solucionaría si    encontrase otro elfo de fuego.
DIANA                            Estamos bien lejos en el sureste,no vas a encontrarlos por aquí.
MAPLE                            Ya, seguiré buscando entonces    aunque esta isla es pequeña.
DIANA                            Buena suerte, jaja. Cuídate      mucho, Maple.
MAPLE                            Diana! Hé!
DIANA                            Hé, Maple! Un tel cœur?
MAPLE                            Bon, bien qu'un peu terne.
DIANA                            Avez-vous regardé l'émission ce matin?
MAPLE                            Celui que Rufus a piraté? C'est un idiot, tout ira bien.
MAPLE                            Peut-être que maintenant il pense qu'il est un super méchant ou quelque chose comme ça.
DIANA                            Des mecs comme ça me font rire aux éclats, vraiment. MDR!
MAPLE                            Et vous le dites. Mais préviens-moi si tu le vois dans le coin.
MAPLE                            Fried alligator est un régal à cette période de l'année.
DIANA                            Je le ferai.
DIANA                            Qu'en dites-vous?
MAPLE                            Avez-vous vu Scout? Ce pauvre garçon a été attrapé par moi.
MAPLE                            C'est un gars adorable, mais je devrai lui faire comprendre au fil du temps qu'il n'est définitivement pas mon genre.
DIANA                            Fille, je n'envie pas ta situation, haha. Cest quoi ton type?
MAPLE                            J'aimerais quelqu'un qui est fou et qui me fait me sentir excité.
MAPLE                            Tous les garçons agissent comme si elle était une déesse et tout finit toujours pareil. Je pourrais faire un barbecue avec eux si je le voulais.
DIANA                            Heh, peut-être que tout le monde te traite comme ça parce que tu finis par leur faire peur.
MAPLE                            Comme si tout serait résolu s'il trouvait un autre elfe du feu.
DIANA                            Nous sommes loin dans le sud-est, vous ne les trouverez pas par ici.
MAPLE                            Ouais, je vais continuer à chercher alors même si cette île est petite.
DIANA                            Bonne chance, ha ha. Prends bien soin de toi, Maple.

ENOKI                            ¡Hey, chica!
DIANA                            Enoki, ¡ma cherie! ¿Quieres algo de picoteo?
ENOKI                            Siempre quiero algo de picoteo.
DIANA                            Jaja, así me gusta. ¿Qué tal fue tu día?
ENOKI                            Bien, bien, aunque estoy un poco preocupada.
DIANA                            Aw, ¿y eso?
ENOKI                            Bueno, Aaron y Maple han tenido  bronca hoy.
DIANA                            ¡Qué mal! ¿Ha pasado algo?
ENOKI                            Bueno Aaron siempre reprime lo   que quiere decir.
ENOKI                            Y Maple lo dice todo a la cara   sin pensar en tus sentimientos.
DIANA                            Esa es una terrible combinación.
ENOKI                            Ocurre todo el tiempo pero me    pone triste cada vez que pasa.
DIANA                            No tengo hermanos pero... ¿No es algo que siempre ocurre?
ENOKI                            ¿Tú también eres hija única? Me  habría gustado tener hermana.
DIANA                            Tengo un hermano pequeño, aunque no solemos tener mucho drama.
ENOKI                            Entiendo, entiendo.
DIANA                            Mantenme al tanto, ¿vale?
ENOKI                            Vale.
ENOKI                            Hé fille!
DIANA                            Enoki, ma chérie! Voulez-vous une collation?
ENOKI                            Je veux toujours quelque chose à grignoter.
DIANA                            Haha, j'aime ça comme ça. Comment s'est passée ta journée?
ENOKI                            Bon, bon, même si je suis un peu inquiet.
DIANA                            Ah, et ça?
ENOKI                            Eh bien, Aaron et Maple se sont disputés aujourd'hui.
DIANA                            Quel mal! Quelque chose est arrivé?
ENOKI                            Et bien Aaron retient toujours ce qu'il veut dire.
ENOKI                            Y Maple vous dit tout en face sans penser à vos sentiments.
DIANA                            C'est une terrible combinaison.
ENOKI                            Ça arrive tout le temps mais ça me rend triste à chaque fois que ça arrive.
DIANA                            Je n'ai pas de frères et sœurs mais... N'est-ce pas quelque chose qui arrive toujours?
ENOKI                            Êtes-vous aussi enfant unique? J'aurais aimé avoir une sœur.
DIANA                            J'ai un petit frère, bien que nous-autres n'ayons généralement pas beaucoup de drames.
ENOKI                            Je comprends, je comprends.
DIANA                            Tenez-moi au courant, d'accord?
ENOKI                            D'accord.

DIANA                            ¡Hey, Aaron!                     ¿En qué puedo ayudarte?
AARON                            ¿Te has enterado de lo del juego de mesa esta noche, no?
DIANA                            ¡Sí! Allí estaré. ¿Has visto la  transmisión?
AARON                            Hablé con Maple, y parece conocera ese chico Plonj.
AARON                            A ella no le preocupa demasiado.
DIANA                            Oh, me alegra oír eso.           ¿Te veo a la noche?
AARON                            ¡Por supuesto!
DIANA                            Hé, Aaron! En quoi je peux t'aider?
AARON                            Tu as entendu parler du jeu de société ce soir, n'est-ce pas?
DIANA                            Oui! Je serai là. Avez-vous vu l'émission?
AARON                            J'ai parlé à Maple, et elle semble connaître ce garçon de Plonj.
AARON                            Elle s'en fiche un peu.
DIANA                            Oh, je suis contente d'entendre ça. On se voit ce soir?
AARON                            Bien sûr!

SCOUT                            ¡Hey! Soy yo, Scout.
DIANA                            ¡Hey Scout! ¿Qué te cuentas?
SCOUT                            Parece que el Scout TV de este   mes ha concluído.
SCOUT                            Ahora sólo tengo que preocuparme por la próxima Scout Expo.
DIANA                            Aún sigues hablando de ello,     ¿qué es exactamente?
SCOUT                            Oh, es un lugar en el que saco   mis nuevas invenciones y
SCOUT                            las enseño. Normalmente lo grabo todo en vídeo y lo subo
SCOUT                            a internet, ¡pero ahora he       conseguido amigos a los que
SCOUT                            poder mostrarle mis artilugios!
DIANA                            ¡Eso parece divertido! ¿Podrías  enseñarme algo de ejemplo?
SCOUT                            ¡No seas aguafiestas! Espera a laScout Expo y podrás verlos.
DIANA                            Está bien... Sólo tenía          curiosidad.
SCOUT                            ... Bueno, pues he creado este   dispositivo-
DIANA                            ¿Pero no acabas de decirme que   no podías enseñarme nada?
SCOUT                            Pero Yo- Y... hmm... vale.       También me costará esperar.
DIANA                            Je, sabía que te podría el ansia.
SCOUT                            Hé! C'est moi, scout.
DIANA                            Hé Scout! Quoi de neuf?
SCOUT                            Il semble que le Scout TV de ce mois-ci soit terminé.
SCOUT                            Maintenant, je n'ai plus qu'à m'occuper de la prochaine Expo Scout.
DIANA                            Tu en parles encore, qu'est-ce que c'est exactement?
SCOUT                            Oh, c'est un endroit où je sors mes nouvelles inventions et je les montre. D'habitude, je filme tout et je le poste en ligne, mais maintenant j'ai des amis à qui je peux montrer mes gadgets!
DIANA                            Ça a l'air amusant! Pourriez-vous me montrer un exemple?
SCOUT                            Ne soyez pas un trouble-fête! Attendez l'Expo Scout et vous pourrez les voir.
DIANA                            D'accord... J'étais juste curieuse.
SCOUT                            ...Eh bien, j'ai créé cet appareil-
DIANA                            Mais ne viens-tu pas de me dire que tu ne pouvais rien m'apprendre?
SCOUT                            Mais je- Et... hmm... d'accord. J'aurai aussi du mal à attendre.
DIANA                            Heh, je savais que l'envie te prendrait.

DIANA                            ¡Hey, Vee! ¿Cómo andas?
OLIVIER                          Bien, bien.
DIANA                            ¿Has venido para pedirme que     organice alguna partida aquí?
OLIVIER                          ¡Qué va! En absoluto...          Vamos a jugar fuera.
OLIVIER                          Y si todo va bien espero que la  isla no salga ardiendo.
OLIVIER                          ¿Cómo se encuentran los tuyos?
DIANA                            ¡De maravilla! A mis padres les  gustaría pasarse alguna vez.
DIANA                            Aunque mi casa está hecha un     desastre. ¿Me dejas la tuya?
OLIVIER                          Sigue soñando, jajaja.
OLIVIER                          Debería invitar a Eleanor y a la familia a venir algún día.
DIANA                            Oh, les encantará este sitio.
DIANA                            Espero que nada pueda salir mal.
OLIVIER                          Esperemos que no jajaja.
DIANA                            Hé, tu vois! Comment ça va?
OLIVIER                          Bien, bien.
DIANA                            Tu viens me demander d'organiser un jeu ici?
OLIVIER                          Quoi de neuf! Pas du tout... Jouons dehors.
OLIVIER                          Et si tout va bien, j'espère que l'île ne s'enflamme pas.
OLIVIER                          Comment vont les vôtres?
DIANA                            Merveilleux! Mes parents aimeraient y passer un jour.
DIANA                            Bien que ma maison soit en désordre. Peux-tu me laisser le tien?
OLIVIER                          Continuez à rêver, hahaha.
OLIVIER                          Je devrais inviter Eleanor et la famille un jour.
DIANA                            Oh, tu vas adorer cet endroit.
DIANA                            J'espère que tout va bien.
OLIVIER                          Espérons que non lol.

ELEANOR                          ¡Bonjour!
DIANA                            ¡Salut, ma charie! ¿Quoi de neuf?
ELEANOR                          Oh, ¿Qué es ese olor? ¿Estabas   amasando algo?
DIANA                            Qué va, jeje. Aunque debo recogermi habitación...
DIANA                            ¿Cómo has estado?                ¿Alguna novedad?
ELEANOR                          No mucho, he estado cosiendo una nueva colcha.
DIANA                            Fantástico. ¿De qué la estás     haciendo ahora?
ELEANOR                          Traje toda la ropa de mi pueblo  natal a la isla.
ELEANOR                          Está toda hecha polvo pero me da pena deshacerme de la ropa.
ELEANOR                          Han estado siempre conmigo así   que haré una colcha con ella.
DIANA                            Aw, te quedará genial.
DIANA                            ¿Has vuelto a dibujar?
ELEANOR                          ¡Un poco! Hay muchos paisajes    bellos por aquí.
DIANA                            Podría tocar la guitarra junto alocéano el resto de mi vida.
DIANA                            Bueno, cuando digo océano me     refiero también al lago.
DIANA                            ¿O tal vez me refiero   al mar? Me estoy liando ya jajaja.
ELEANOR                          En cualquier caso, eso suena     muy divertido.
DIANA                            Arrrrrrrg, ¡es la hora pirata!
DIANA                            No te preocupes, pasaré de visitaaunque siempre esté navegando
ELEANOR                          ¡S'il vous plait!
ELEANOR                          Bonjour!
DIANA                            Bonjour ma chérie! What's up?
ELEANOR                          Oh, quelle est cette odeur? Étais tu en train de pétrir quelque chose?
DIANA                            Quoi de neuf, hehe. Même si je dois vider ma chambre...
DIANA                            Comment vas-tu? Quelque chose de nouveau?
ELEANOR                          Il n'y a pas longtemps, j'ai cousu un nouveau quilt.
DIANA                            Fantastique. Tu en fais quoi à partir de maintenant?
ELEANOR                          J'ai apporté tous les vêtements de ma ville natale sur l'île.
ELEANOR                          Elle est toute crevée mais j'ai honte de me débarrasser de ses vêtements.
ELEANOR                          Ils ont toujours été avec moi alors je vais en faire une courtepointe.
DIANA                            Aw, ça ira très bien sur toi.
DIANA                            Avez-tu encore dessiné?
ELEANOR                          Un peu! Il y a beaucoup de beaux paysages ici.
DIANA                            Je pourrais jouer de la guitare avec l'océan pour le reste de ma vie.
DIANA                            Well, quand je dis océan, je veux dire aussi le lac.
DIANA                            Ou peut-être que je veux dire la mer? Je déconne hahaha.
ELEANOR En tout cas, ça a l'air très amusant.
DIANA                            Arrrrrrrg, c'est l'heure des pirates!
DIANA                            Ne tu inquiétez pas, je visiterai même si je suis toujours en train de naviguer
ELEANOR                          S'il te plait!

DIANA                            ¡Hey! ¿Eras Guy, no?
GUY                              ¡Ese soy yo! ¿Vives aquí?
DIANA                            Es humilde pero es mi nuevo      hogar. ¿Te gusta?
GUY                              Desde muy pequeño soñaba con     tener mi propia cocina de
GUY                              tamaño industrial junto a una    cama abatible.
DIANA                            Eso es un sueño excesivamente    explícito, pero lo entiendo.
GUY                              Ni siquiera tienes cocina en tu  cabaña, ¿cierto?
DIANA                            Tenemos un horno y una           mini nevera, jaja.
DIANA                            Traigo productos importados así  que como mucha comida en lata
GUY                              Sabes que la comida enlatada no  es muy saludable, ¿no?
DIANA                            Sí, bueno, ya tendré tiempo para preocuparme por esas cosas.
DIANA                            Todo el mundo engorda y envejece algún día.
GUY                              Yo no. Algún día estaré mayor    pero siempre sano y delgado.
DIANA                            Ya veremos quién está mejor      cuando lleguemos a los 50.
GUY                              Más bien ya verás tú,            llegado el momento.
DIANA                            Vamos a jugar a un juego de mesa esta noche. ¿Vienes?
GUY                              Nah, estaré ocupado con mi cocinatoda la noche.
DIANA                            Ah... Vale, lo entiendo.         ¡Pásalo guay!
DIANA                            Ya me dirás qué tal.
GUY                              ¡Claro!.
DIANA                            Salut! Vous étiez Guy, n'est-ce pas?
GUY C'est moi! Tu vis ici?
DIANA                            C'est humble mais c'est ma nouvelle maison. Tu aimes?
GUY Dès mon plus jeune âge, je rêvais d'avoir ma propre cuisine de taille industrielle à côté d'un lit escamotable.
DIANA                            C'est un rêve trop explicite, mais je comprends.
GUY Tu n'as même pas de cuisine dans ta cabine, n'est-ce pas?
DIANA                            Nous avons un four et un mini frigo, haha.
DIANA                            J'apporte des produits importés donc je mange beaucoup de conserves
GUY Vous savez que la nourriture en conserve n'est pas très saine, n'est-ce pas?
DIANA                            Oui, eh bien, j'aurai le temps de m'occuper de ces choses.
DIANA                            Tout le monde devient gros et vieux un jour.
GUY Pas moi. Un jour, je serai plus vieux mais toujours en bonne santé et mince.
DIANA                            Nous verrons qui est le meilleur quand nous-autres atteindrons 50 ans.
GUY Plutôt, tu verras, le moment venu.
DIANA                            Nous allons jouer à un jeu de société ce soir. Tu viens?
GUY Non, je vais être occupé avec ma cuisine toute la nuit.
DIANA                            Oh... D'accord, j'ai compris. S'amuser!
DIANA                            Tu me diras comment c'est.
GUY Bien sûr!

OLIVIER                          ¡O-Oh! Disculpe, señora.         ¿De dónde viene?
GRAND-MÈRE CORINNE               Este invernadero sigue viéndose  muy bien. ¿Lo han traído?
OLIVIER                          Oh, me dijeron que lo habían     traído de fuera.
GRAND-MÈRE CORINNE               Verás joven, este invernadero    antes era mío.
GRAND-MÈRE CORINNE               Creo que no tiene sentido        ocultarlo, soy un fantasma.
OLIVIER                          ¿¿¿Un fantasma???
GRAND-MÈRE CORINNE               Parece que estoy condenada a     perseguir este invernadero.
OLIVIER                          Mis disculpas... Eso parece un   terrible destino...
GRAND-MÈRE CORINNE               ¿Considerarías terrible pasar    una eternidad aquí?
OLIVIER                          Pensándolo bien... Supongo que   no está tan mal.
OLIVIER                          El tiempo que he pasado aquí     ha sido agradable.
GRAND-MÈRE CORINNE               Veo que disfrutas cuidando de    estas plantas, joven.
GRAND-MÈRE CORINNE               Déjame decirte algo antes        de despedirme.
GRAND-MÈRE CORINNE               Aunque cuidar de las plantas     parece no tener sentido.
GRAND-MÈRE CORINNE               Un maravilloso porvenir aguarda  a las personas diligentes.
GRAND-MÈRE CORINNE               Ha sido un placer conocerte.     ¡Cuídate mucho!
OLIVIER                          O-Oh! Excusez-moi Madame. D'où il vient?
GRAND-MÈRE CORINNE               Cette serre a toujours fière allure. L'ont-ils apporté?
OLIVIER                          Oh, ils m'ont dit qu'ils l'avaient apporté de l'extérieur.
GRAND-MÈRE CORINNE               Tu vois jeune homme, cette serre était la mienne.
GRAND-MÈRE CORINNE               Je pense qu'il ne sert à rien de le cacher, je suis un fantôme.
OLIVIER                          Un fantôme???
GRAND-MÈRE CORINNE               Il semble que je sois condamné à persécuter cette serre.
OLIVIER                          Mes excuses... Cela semble être un sort terrible...
GRAND-MÈRE CORINNE               Vous trouveriez terrible de passer une éternité ici?
OLIVIER                          A la réflexion... Je suppose que ce n'est pas si mal.
OLIVIER                          Mon séjour ici a été agréable.
GRAND-MÈRE CORINNE               Je vois que tu aimes entretenir ces plantes, jeune homme.
GRAND-MÈRE CORINNE               Laissez-moi vous dire quelque chose avant de vous dire au revoir.
GRAND-MÈRE CORINNE               S'occuper des plantes semble pourtant inutile.
GRAND-MÈRE CORINNE               Un bel avenir attend les gens assidus.
GRAND-MÈRE CORINNE               Ce fut un plaisir de vous rencontrer. Prends soin de toi!
    
OLIVIER                          ¡O-Oh! Disculpe, señora.         ¿De dónde viene?
GRAND-MÈRE CORINNE               Este invernadero sigue viéndose  muy bien. ¿Lo han traído?
OLIVIER                          Oh, me dijeron que lo habían     traído de fuera.
GRAND-MÈRE CORINNE               Verás joven, este invernadero    antes era mío.
GRAND-MÈRE CORINNE               Creo que no tiene sentido        ocultarlo, soy un fantasma.
OLIVIER                          ¿¿¿Un fantasma???
GRAND-MÈRE CORINNE               Parece que estoy condenada a     perseguir este invernadero.
OLIVIER                          Mis disculpas... Eso parece un   terrible destino...
GRAND-MÈRE CORINNE               ¿Considerarías terrible pasar    una eternidad aquí?
OLIVIER                          Pensándolo bien... Supongo que   no está tan mal.
OLIVIER                          El tiempo que he pasado aquí     ha sido agradable.
GRAND-MÈRE CORINNE               Veo que disfrutas cuidando de    estas plantas, joven.
GRAND-MÈRE CORINNE               Déjame decirte algo antes        de despedirme.
GRAND-MÈRE CORINNE               Aunque cuidar de las plantas     parece no tener sentido.
GRAND-MÈRE CORINNE               Un maravilloso porvenir aguarda  a las personas diligentes.
GRAND-MÈRE CORINNE               Ha sido un placer conocerte.     ¡Cuídate mucho!
OLIVIER                          O-Oh! Excusez-moi Madame. D'où il vient?
GRAND-MÈRE CORINNE               Cette serre a toujours fière allure. L'ont-ils apporté?
OLIVIER                          Oh, ils m'ont dit qu'ils l'avaient apporté de l'extérieur.
GRAND-MÈRE CORINNE               Tu vois jeune homme, cette serre était la mienne.
GRAND-MÈRE CORINNE               Je pense qu'il ne sert à rien de le cacher, je suis un fantôme.
OLIVIER                          Un fantôme???
GRAND-MÈRE CORINNE               Il semble que je sois condamné à persécuter cette serre.
OLIVIER                          Mes excuses... Cela semble être un sort terrible...
GRAND-MÈRE CORINNE               Tu trouveras terrible de passer une éternité ici?
OLIVIER                          A la réflexion... Je suppose que ce n'est pas si mal.
OLIVIER                          Mon séjour ici a été agréable.
GRAND-MÈRE CORINNE               Je vois que tu aimes entretenir ces plantes, jeune homme.
GRAND-MÈRE CORINNE               Laissez-moi te dire quelque chose avant de te dire au revoir.
GRAND-MÈRE CORINNE               S'occuper des plantes semble pourtant inutile.
GRAND-MÈRE CORINNE               Un bel avenir attend les gens assidus.
GRAND-MÈRE CORINNE               Ce fut un plaisir de te rencontrer. Prends soin de toi!

CESAR'S BIZAAR                   'SÓLO TENEMOS DOS ARTÍCULOS,     ES LO QUE HAY'

LE BIZAAR D’CESAR                'NOUS AVONS SEULEMENT DEUX ARTICLES, C'EST CE QUE vous autres OBTENEZ'

MAPLE                            Así que... Guy, uhg...  ¿Pusiste tomate en la Jambalaya?
GUY                              Así lo quiso Dios, nuestro señor.
MAPLE                            ¿C-cómo que así lo quiso Dios?
MAPLE                            ... Me estás tomando el pelo,    ¿no es así?
GUY                              ¿También eres una de esas a las  que les gusta su roux quemada?
MAPLE                            Define 'quemada'.
GUY                              Tan quemado que pierde tanto el  color y no puedes saborearlo.
MAPLE                            ¿A qué te refieres con eso del   sabor? ¡A mí me gusta así!
GUY                              Sí, porque lo entierras en un    montón de especias al azar.
MAPLE                            Mi elección de especias NO es    al azar.
GUY                              No tengo más que decir, si me    disculpas, barreré el suelo
GUY                              de la cocina para hacer una      buena jambalaya.
MAPLE                            Los criollos estáis fatal        de la olla.
GUY                              Pas autant que les acadiens, ma  fille. Tu vois ce que je te dis?
GUY                              Hagamos un concurso de hacer     gumbo y dejemos que los demás juzguen, ¿eh?
MAPLE                            Trato hecho.                     Será coser y cantar.
MAPLE                            Alors... Mec, uhg... As-tu mis de la tomate sur le Jambalaya?
GUY                              C'est comme ça que Dieu l'a voulu, notre Seigneur.
MAPLE                            Comment Dieu a-t-il voulu qu'il en soit ainsi?
MAPLE                            ...Vous moquez de moi, n'est-ce pas?
GUY                              Tu fais aussi partie de ceux qui aiment leur roux brûlé?
MAPLE                            Définit 'brûlé'.
GUY                              Tellement brûlé qu'il perd tellement de couleur qu'on ne peut plus le goûter.
MAPLE                            Qu'entendez-vous par le goût? j'aime bien ça!
GUY                              Oui, parce que tu l'enterre dans un tas d'épices au hasard.
MAPLE                            Mon choix d'épices n'est PAS aléatoire.
GUY                              j'ai plus rien à dire, si tu veux bien m'excuser, je vais balayer le sol
GUY                              de la cuisine pour faire un bon jambalaya.
MAPLE                            Les créoles sont mortelles dès le pot.
GUY                              Pas autant que les acadiens, ma fille, tu vois ce que je te dis?
GUY                              Organisons un concours de fabrication de gombos et laissons les autres juger, hein?
MAPLE                            Affaire conclue. C'est de la tarte.
    
ENOKI                            Ooooooh... ¡Me encanta tu cocina!¡Es enormísima!
GUY                              Merci. Aunque tengo ganas de    salir y comer paz de maíz.
ENOKI                            Me encantaría eso también, jeje.
GUY                              Por cierto, uh. Esa tal Maple... ¿Es mejor su gumbo o el mío?
ENOKI                            ¿Estás compitiendo con ella?     Si es así, no quiero elegir.
ENOKI                            No quiero ponerme en tu contra   ahora que te has mudado aquí.
ENOKI                            Pero has de saber que Maple y yo somos mejores amigas.
GUY                              Tal vez pueda cocinarte un gumbo que te haga reconsiderarlo.
ENOKI                            Lo veo complicado. No me gusta   mucho /ese/ plato en concreto.
GUY                              Pero... Ah, qué más dá.          Cuídate, cheri.
ENOKI                            Ooooooh... j'adore ta cuisine, elle est immense!
GUY                              Merci. Même si j'ai envie de sortir et de manger du maïs en paix.
ENOKI                            J'aimerais ça aussi, hehe.
GUY                              Au fait, euh. Cette personne d'Maple... Est-ce que son gombo est meilleur ou le mien?
ENOKI                            Es-tu en compétition avec elle? Si oui, je ne veux pas choisir.
ENOKI                            Je ne veux pas me retourner contre toi maintenant que tu as déménagé ici.
ENOKI                            Mais tu devrais savoir que Maple et moi sommes les meilleurs amis.
GUY                              Peut-être que je peux te cuisiner un gombo qui te fera reconsidérer.
ENOKI                            je vois ça compliqué. Je n'aime pas vraiment /ce/ plat en particulier.
GUY                              Mais... Ah, anyway. Prends soin de toi, chérie.
    
AARON                            ¡Huele muy bien aquí!
GUY                              Oui, así ha de ser.
AARON                            Oye, ¿escuché que viniste aquí   en busca de clientes?
GUY                              Eso es cierto.
AARON                            Bueno, eh... Como puedes comprobar, no somos muchos por aquí.
AARON                            Aunque trato de convertir la islaen un lugar al que llamar hogar.
GUY                              ¿A dónde quieres llegar?
AARON                            Solo espero que sepas que no     somos lo bastante grandes como
AARON                            para tener nuestra propia moneda,algunos apenas tienen dinero.
GUY                              Sólo cobro 5 dólares, es         accesible y espero clientes.
AARON                            ¿Sabes qué? ¿Cuánto cuesta esta  cabaña? ¿10 o 20 mil dólares? 
AARON                            No sé hacer cálculos, nunca me   gradué en la escuela secundaria.
AARON                            No está aquí, pero Enoki puede   hacer cálculos complejos.
AARON                            ¿Qué tal si nos das comida gratisdurante el resto del año?
AARON                            Entonces tú tendrás que pagarla. ¿C'est bon?
GUY                              ... Me lo pensaré.
AARON                            Ça sent bon ici!
GUY                              Oui, c'est comme ça que ça doit être.
AARON                            Hé, j'ai entendu dire que tu étais venu chercher des clients?
GUY                              C'est vrai.
AARON                            Well, euh... Comme vous pouvez le voir, nous-autres ne sommes pas nombreux par ici.
AARON                            Bien que j'essaie de faire de l'île un chez-soi.
GUY                              Où veux-tu aller?
AARON                            J'espère juste que vous savez que nous-autres ne sommes pas assez grands pour avoir notre propre monnaie, certains ont à peine de l'argent.
GUY                              Mo ne facture que 5 dollars, c'est abordable et j'attends des clients.
AARON                            Tu connais what? Combien coûte cette cabane? 10 ou 20 mille dollars?
AARON                            Je ne sais pas faire de maths, je n'ai jamais obtenu mon diplôme d'études secondaires.
AARON                            Il n'est pas là, mais Enoki peut faire des calculs complexes.
AARON                            Et si vous nous-autres donniez de la nourriture gratuite pour le reste de l'année?
AARON                            Alors tu devras payer pour ça. C'est bon?
GUY                              ...Mo vais y réfléchir.
    
OLIVIER                          ¡O-Oh! Disculpe, señora.         ¿De dónde viene?
GRAND-MÈRE CORINNE               Este invernadero sigue viéndose  muy bien. ¿Lo han traído?
OLIVIER                          Oh, me dijeron que lo habían     traído de fuera.
GRAND-MÈRE CORINNE               Verás joven, este invernadero    antes era mío.
GRAND-MÈRE CORINNE               Creo que no tiene sentido        ocultarlo, soy un fantasma.
OLIVIER                          ¿¿¿Un fantasma???
GRAND-MÈRE CORINNE               Parece que estoy condenada a     perseguir este invernadero.
OLIVIER                          Mis disculpas... Eso parece un   terrible destino...
GRAND-MÈRE CORINNE               ¿Considerarías terrible pasar    una eternidad aquí?
OLIVIER                          Pensándolo bien... Supongo que   no está tan mal.
OLIVIER                          El tiempo que he pasado aquí     ha sido agradable.
GRAND-MÈRE CORINNE               Veo que disfrutas cuidando de    estas plantas, joven.
GRAND-MÈRE CORINNE               Déjame decirte algo antes        de despedirme.
GRAND-MÈRE CORINNE               Aunque cuidar de las plantas     parece no tener sentido.
GRAND-MÈRE CORINNE               Un maravilloso porvenir aguarda  a las personas diligentes.
GRAND-MÈRE CORINNE               Ha sido un placer conocerte.     ¡Cuídate mucho!
OLIVIER                          O-Oh! Excusez-moi Madame. D'où il vient?
GRAND-MÈRE CORINNE               Cette serre a toujours fière allure. L'ont-ils apporté?
OLIVIER                          Oh, ils m'ont dit qu'ils l'avaient apporté de l'extérieur.
GRAND-MÈRE CORINNE               Tu vois jeune homme, cette serre était la mienne.
GRAND-MÈRE CORINNE               Je pense qu'il ne sert à rien de le cacher, je suis un fantôme.
OLIVIER                          Un fantôme???
GRAND-MÈRE CORINNE               Il semble que je sois condamné à persécuter cette serre.
OLIVIER                          Mes excuses... Cela semble être un sort terrible...
GRAND-MÈRE CORINNE               Tu trouveras terrible de passer une éternité ici?
OLIVIER                          A la réflexion... Je suppose que ce n'est pas si mal.
OLIVIER                          Mon séjour ici a été agréable.
GRAND-MÈRE CORINNE               Je vois que tu aimes entretenir ces plantes, jeune homme.
GRAND-MÈRE CORINNE               Laissez-moi te dire quelque chose avant de te dire au revoir.
GRAND-MÈRE CORINNE               S'occuper des plantes semble pourtant inutile.
GRAND-MÈRE CORINNE               Un bel avenir attend les gens assidus.
GRAND-MÈRE CORINNE               Ce fut un plaisir de te rencontrer. Prends soin de toi!

OLIVIER                          ¡Bonjour!
GUY                              Oui. ¿J'suppose que eres el chicodel jardín?
GUY                              ¿Cultivas apio, cebolla y        pimientos?
OLIVIER                          ¡Por supuesto!
GUY                              ¿Sabes? Podrías conseguirme      mercancía fresca.
GUY                              A cambio te cocinaré gumbo       totalmente gratis.
OLIVIER                          ¿Y qué hay de mi esposa?
GUY                              ¿Es la que tiene el atuendo y el cabello de Wendy?
OLIVIER                          ...Es la que tiene el pelo       marrón.
GUY                              Ya veo, Dave.
OLIVIER                          ...Olivier. Olivier Landry.
OLIVIER                          ¿No te llamas Guy?
GUY                              Correcto.
OLIVIER                          ¿Pero no era 'Guy Pizza'?
GUY                              Eso era una broma, pero no se lo digas a nadie. ¿Vale?
OLIVIER                          Entendido.
OLIVIER                          Bonjour!
GUY                              Oui. Suppose que tu es le jardinier?
GUY                              Cultivez-vous du céleri, de l'oignon et des poivrons?
OLIVIER                          Bien sûr!
GUY                              Tu connais? Vous pourriez m'apporter de la marchandise fraîche.
GUY                              En retour, mô te cuisinerai du gombo gratuitement.
OLIVIER                          Et ma femme?
GUY                              C'est celui avec la tenue et les cheveux de Wendy?
OLIVIER                          ...C'est celle qui a les cheveux bruns.
GUY                              Mo vois, Dave.
OLIVIER                          ...Olivier. Olivier Landry.
OLIVIER                          Vous ne vous appelez pas Guy?
GUY                              Correct.
OLIVIER                          Mais n'était-ce pas ‘Guy Pizza’?
GUY                              C'était une blague, mais ne le dis à personne. Bien?
OLIVIER                          Compris.
    
ELEANOR                          ¡Bonjour! ¿Comment allez-vous?
GUY                              C'est bon, ¿y tú cómo estás?
ELEANOR                          Este lugar me hace sentir muy    hambrienta, ¡y huele genial!
GUY                              ¿En serio?
ELEANOR                          Me gusta más hornear que cocinar,¡pero esta cocina es estupenda!
GUY                              ¿Qué te gusta hacer en el horno?
ELEANOR                          Lo que más me gusta es el pastel de lima, aunque necesito
ELEANOR                          hacer un montón de praliné de    nuez. ¿Te gusta el praliné?
GUY                              ¿Que si me gusta el praliné?
GUY                              ¿QUE SI ME GUSTA EL PRALINÉ?
GUY                              Y tanto, está riquísimo.
GUY                              Consígueme praliné y te daré     comida gratis. ¿Te parece bien?
ELEANOR                          ¡Trato hecho!
ELEANOR                          Bonjour! Comment allez-vous?
GUY                              C'est bon, et comment vas-tu?
ELEANOR                          Cet endroit me donne vraiment faim, et ça sent bon!
GUY                              Vraiment?
ELEANOR                          J'aime pâtisser plus que cuisiner, mais cette cuisine est géniale!
GUY                              Qu'est-ce que tu aimes faire au four?
ELEANOR                          Ma préférée est la tarte au citron vert, même si je dois faire beaucoup de pacanes pralinées. Vous aimez le praliné?
GUY                              Et si j'aime le praliné?
GUY                              ET SI J'AIME LA PRALINE?
GUY                              Et donc, c'est délicieux.
GUY                              Apportez-moi des pralines et mô vous donnerai de la nourriture gratuite. Pensez-vous que c'est OK?
ELEANOR                          Affaire conclue!
    
DIANA                            ¡Hey! Tu nombre era Guy Pizza    si mal no recuerdo, ¿cierto?
GUY                              Guy Pizza, únice e inimitable.
DIANA                            Puedo entender por qué, jajaja.  ¿Eres italiano?
GUY                              Nah, soy de Donaldsonville.      Nuevo nombre, nueva vida.
DIANA                            ¿Y por qué elegiste llamarte a   'pizza' a ti mismo?
GUY                              La gente lleva años llamándome   'pizza guy' y mi nombre es Guy.
GUY                              Estoy acostumbrado a eso. Además hago que la gente tenga hambre.
DIANA                            Claro, a cualquiera le apetece   una pizza. ¿Las haces a menudo?
GUY                              Pues no suelo hacerlas,          la verdad.
DIANA                            Supongo que no es demasiado tardepara que cambies de parecer.
GUY                              ¿Tienes alguna sugerencia?
DIANA                            Guy... el Misterioso. A la gente le gusta lo enigmático
GUY                              Pero no soy un mago...
DIANA                            Tampoco eres una pizza.
GUY                              Touché.
GUY                              Tendré tu sugerencia en cuenta.
DIANA                            Salut! Votre nom était Guy Pizza si je me souviens bien, n'est-ce pas?
GUY                              Guy Pizza, the one and only.
DIANA                            Je peux comprendre pourquoi, lol. Tu es italien?
GUY                              Non, mo viens de Donaldsonville. Nouveau nom, nouvelle vie.
DIANA                            Et pourquoi avez-vous choisi de vous appeler 'pizza'?
GUY                              Les gens m'appellent "pizza guy" depuis des années.
GUY                              M'ai l'habitude de ça. En plus, je rends les gens affamés.
DIANA                            Bien sûr, tout le monde veut une pizza. Les faites-vous souvent?
GUY                              Eh bien, moi ne les fais pas habituellement, vraiment.
DIANA                            Je suppose qu'il n'est pas trop tard pour que tu changes d'avis.
GUY                              Avez-vous des suggestions?
DIANA                            Guy... le Mystérieux. Les gens aiment l'énigmatique
GUY                              I’m not a magician.
DIANA                            Tu n'es pas une pizza non plus.
GUY                              Touche.
GUY                              Mo vais prendre en compte votre suggestion.
    
AARON                            Parece que no hay nadie en casa.
AARON                            On dirait qu'il n'y a personne à la maison.
Chapter 2 intro

SCOUT                            Hey, y'all! Scout here.                                           It's that time again!
                                 Scout TV is a regular thing goingon! Check it out, I feel like a  real reporter now!
                                 We've all been on this island forthree good months, now. I can't  decide if it feels more like a   day or a million years long.
                                 Well, it's taken a while, but it looks like we're getting two new islanders!
                                 We've got a certain Cesar de la  Cruz on special invitation from  our very own Queen Enoki.
                                 He was apparently a famous lawyerwho's decided that he wants a newstart.
                                 We've also got a guy moving in   whose name is.. Guy. I'm not     kidding - his name is Guy.
                                 I'm looking forward to seeing    what he cooks up, literally! He'sa cook and apparently makes a    mean jambalaya.
                                 Now, we're getting ever closer tothe Scout Expo, and it's only a  matter of time before it's all   ready.
                                 I've also managed to order a     bunch of new Time Raiders comic, cuz I know a bunch of islanders  have really been getting into-

                                 . . . .
RUFUS                            I, er- hmm.. Yes, good evening,  island neighbors. It is I, Rufus Thibodeaux, and if you do not    know me, you soon will.
                                 I have interrupted this broadcastto let you know that I am giving you an ultimatum. Either you     submit your island to me, or-!
                                 . . . .

                                 -and that's all, folks! See y'allnext time!
ENOKI                            Aw, I missed the end of the Scoutbroadcast. I was looking forward to it.
MAPLE                            Hey, isn't that twerp Del's      nephew? He, uh, stopped by the   island a few months ago, I think.
AARON                            What a strange broadcast.
ENOKI                            I'm gonna get a soda.

. . .
SCOUT                            ¡Hola a todos! ¡Scout ha llegado!                                 ¡Y aquí estoy de vuelta!
                                 ¡Scout TV es algo habitual!      Como pueden comprobar, ¡ahora me siento un auténtico reportero!
                                 Todos hemos estado en la isla durante tres meses. ¡No sabría decirsi llevamos un día o un millón   de años!
                                 Bueno. Ha pasado un tiempo desde la última vez, ¡Pero parece que  se nos han unido dos personas    más!
                                 Primero tenemos a César de la    Cruz, un invitado especial de    nuestra Reina Enoki.
                                 Aparentemente, fue un famoso     abogado que ahora busca un nuevo comienzo.
                                 También tenemos a un nuevo chico que se está mudando. ¡Su nombre  es Guy y es cocinero!
                                 ¡Estoy deseando ver su comida!   ¡Su jambalaya tiene una fama     excepcional!
                                 Además nos estamos acercando a   la Scout Expo, ¡y sólo es        cuestión de tiempo tenerla       preparada!
                                 También he pedido un montón de   números de Time Raiders porque   sé que algunos isleños se han    estado metiendo en-
SCOUT                            Salut tout le monde! Scout est arrivé! Et me voilà de retour!
                                 Scout TV est une chose régulière! Comme vous autres pouvez le voir, maintenant je me sens comme un vrai journaliste!
                                 Nous sommes tous sur l'île depuis trois mois. Je ne peux pas dire si ça fait un jour ou un million d'années!
                                 Bon. Cela fait un moment depuis la dernière fois, mais il semble que deux autres personnes se soient jointes à nous!
                                 Nous avons d'abord César de la Cruz, un invité spécial de notre reine Enoki.
                                 Apparemment, il était un célèbre avocat à la recherche d'un nouveau départ.
                                 Nous avons aussi un nouveau gars qui emménage. Il s'appelle Guy et il est cuisinier!
                                 J'ai hâte de voir votre nourriture! Leur jambalaya est exceptionnellement réputé!
                                 De plus, nous-autres nous rapprochons de la Scout Expo, et ce n'est qu'une question de temps pour la préparer!
                                 J'ai aussi commandé un tas de numéros de Time Raiders parce que je sais que certains insulaires se sont mis à...

                                 . . . .
RUFUS                            Yo, er- hmm.. sí, buenas noches, vecinos de la isla. Soy Rufus    Thibodeaux, y si no me conocen   ahora, lo harán más tarde.
                                 Interrumpo esta transmisión para dar un ultimátum. ¡O me entregan la isla o tendré que-!
                                 . . . .

                                 ¡-Y eso es todo, amigos!         ¡Nos vemos la próxima vez!
ENOKI                            Aw, me perdí la transmisión de   Scout... La esperaba             con ansias...
MAPLE                            Oye, ¿ese idiota no era el       sobrino de Del? Se pasó por la   isla hace unos meses, creo.
AARON                            Qué transmisión tan extraña.
ENOKI                            Voy a por un refresco.

. . .
RUFUS                            Moi, euh- hmm.. oui, bonsoir, voisins de l'île. Je suis Rufus Thibodeaux, et si vous autres ne me connaissez pas maintenant, vous autres le saurez plus tard.
                                  J'interromps cette transmission pour donner un ultimatum. Soit ils me donnent l'île, soit je dois-!
                                  . . . .

                                  -Et c'est tous les amis! À la prochaine!
ENOKI                            Aw, j'ai raté l'émission de Scout... Je l'attendais avec impatience...
MAPLE                            Hé, n'était-ce pas le neveu de cet abruti de Del? Il s'est arrêté sur l'île il y a quelques mois, je crois.
AARON                            Quelle étrange transmission.
ENOKI                            Je vais boire un verre.

. . .

Chapter 2 outro




ENOKI                            Hey, Aaron?
AARON                            *yawn* Yeah?
ENOKI                            Are you happy?
AARON                            Of course I am, Noke.
ENOKI                            No, I mean.. Are you really,     actually happy?                  I worry about you.
AARON                            I guess I'm just a little        melancholy about it, that's all.
ENOKI                            What d'you mean?
AARON                            I think you know. Maple is right,we're only able to be here       because of that money you won.
AARON                            We gambled it all, so if anythinghappens to this place, we've got absolutely nothing.
ENOKI                            You know me though, I'm lucky,   we'll be okay. And besides, I gotyou! That's enough.
AARON                            You might not feel like that whenyou're hungry. You don't know    what it's like to be hungry.
ENOKI                            I don't wanna think about this.. it'll keep me up.
ENOKI                            Can we just be happy now and talkabout these things later?  
AARON                            I guess so. Goodnight, Noke.
ENOKI                            Goodnight, Aire.
. . .
ENOKI                            Hey, ¿Aaron?
AARON                            *Awn* ¿Sí?
ENOKI                            ¿Eres feliz?
AARON                            Claro que lo soy, Noke.
ENOKI                            No, a ver... ¿Pero eres feliz de verdad con todo esto?            Me preocupo por ti.
AARON                            Supongo que estoy algo           melancólico al respecto,         eso es todo.
ENOKI                            ¿A qué te refieres?
AARON                            Ya te imaginas. Maple tenía      razón, podemos estar aquí sólo   por el dinero que ganaste.
AARON                            Lo hemos dado todo por este lugary si algo sale mal, No tendremos absolutamente nada.
ENOKI                            Ya me conoces a mí y a mi suerte.Además te tengo a mi lado, eso estodo lo que necesito.
AARON                            Puede que dejes de sentirte así  cuando pases hambre. No sabes lo que es tener hambre.
ENOKI                            No quiero pensar en ello...      Si lo hago, no podré dormir.
ENOKI                            ¿Podemos limitarnos a ser felicesahora mismo? Ya hablaremos de esoen otra ocasión.
AARON                            Supongo que sí. Buenas noches,   Noke.
ENOKI                            Buenas noches, Aire.
. . .
. . .
ENOKI                            Hé, Aaron?
AARON                            *Awn* Oui?
ENOKI                            Êtes-tu heureux?
AARON                            Bien sûr que je le suis, Noke.
ENOKI                            Non, voyons... Mais es-tu vraiment content de tout ça? Je m'inquiète pour toi.
AARON                            Je suppose que je suis un peu sombre à ce sujet, c'est tout.
ENOKI                            Qu'est-ce que tu veux dire?
AARON                            Tu peux imaginer. Maple avait raison, nous-autres ne pouvons être ici que grâce à l'argent que tu as gagné.
AARON                            Nous avons tout donné pour cet endroit et si quelque chose tourne mal, nous-autres n'aurons absolument rien.
ENOKI                            Tu me connais déjà moi et ma chance, en plus je t'ai à mes côtés c'est tout ce dont j'ai besoin.
AARON                            Tu pourrais arrêter de te sentir comme ça quand tu auras faim. Tu ne sais pas ce que c'est que d'avoir faim.
ENOKI                            Je ne veux pas y penser... Si je le fais, je ne pourrai pas dormir.
ENOKI                            Pouvons-nous juste être heureux en ce moment? Nous en reparlerons une autre fois.
AARON                            Je suppose que oui. Bonne nuit, Noc-Noc.
ENOKI                            Bonsoir, mon Air.
. . .
When you walk into the store

CESAR                            Oh! Hey, nice to meet you!       You must be one of the locals.   You can call me Cesar.
                                 Believe it or not, I used to be  a lawyer, you know. I wasn't a   very good one, though.

                                 Then again, I didn't even have a degree and there I was, winning  court cases one after the other.
                                 So why am I telling you all this,despite never having seen you    before?
                                 ...
                                 ...
                                 Just in case we need to keep our narratives straight, oui?
                                 But that's neither here nor      there. I'm fulfilling my dream ofbeing a quiet shopkeep.
                                 If any angry former clients of   mine decide to stop by, just let me know so I can.. er.. hide.    Merci!
                                 Anyway, what might I interest youin today?
CESAR                            ¡Oh! ¡Encantado de conocerte!    Debes ser uno de los locales.    Puedes llamarme César.
                                 Lo creas o no, solía ser abogado.Aunque no era uno precisamente   bueno.

                                 No tenía título y aún así ganaba un caso tras otro.
                                 ¿Que por qué te cuento esto pese a que no nos conocemos de antes?
                                 ...
                                 ...
                                 Es mejor si todos nos conocemos  un poco. ¿No crees?
                                 Me gusta mantenerme ocupado y    estoy cumpliendo mi sueño de ser comerciante en un lugar          tranquilo.
                                 Si ves a algún cliente extraño   que esté enfadado conmigo, avísame para poder... ehm. Esconderme. ¡Merci!
                                 De todas formas, ¿tengo algún    artículo que te llame la atención?
CÉSAR                            Ah! Heureux de vous rencontrer! Vous devez être l'un des habitants. Vous pouvez m'appeler César.
                                 Croyez-le ou non, je suis avocat, mais ce n'était pas vraiment un bon avocat.

                                 Je n'avais pas de titre et gagnait still affaire après affaire.
                                 Pourquoi est-ce que je te dis ça alors que nous-autres ne nous-autres sommes jamais rencontrés auparavant?
                                 ...
                                 ...
                                 C'est mieux si on se connaît tous un peu. Vous ne pensez pas?
                                 J'aime m'occuper et je réalise mon rêve d'être un commerçant dans un endroit calme.
                                 Si vous voyez des clients étrangers qui sont en colère contre moi, faites-le moi savoir pour que je puisse... euh. Cachez-moi Merci!
                                 Quoi qu'il en soit, ai-je un article qui attire votre attention?

When you walk into the store (Enoki)

                                 Enoki Ramirez! Er... Tremblay nowis it? Anyway, thank you so much for letting me come here.
                                 I promise I won't cause any      trouble, but those last clients  of mine...

                                 Look, it's not MY fault that I   was able to pretend to be a      lawyer really well, you know?

                                 I know you understand. Just let  me know if they arrive so I can, you know, er.. hide.
                                 It's been a childhood dream of   mine to be a shopkeep in some    little village, and I don't have a lot to sell,
                                 But I'll do my best! Anyway, how can I help you today?
                                 . . . .
                                 ¡Enoki Ramirez! Er... Ahora      Tremblay, ¿no? Muchas gracias pordejarme venir aquí.
                                 Prometo que no causaré problemas aquí, aunque esos últimos        clientes míos...

                                 Mira, no era culpa MÍA que se me diese tan bien pretender ser un  abogado prestigioso, ¿sabes?

                                 Sé que me entiendes. Sólo avísamesi aparecen buscándome para poderesconderme a tiempo. ¿Vale?
                                 Mi sueño desde crío es ser       tendero en un pueblecito, aunque no tengo mucho para vender.
                                 Ahora que tengo la oportunidad,  ¡daré lo mejor de mí mismo!      ¿Cómo puedo ayudarte hoy?
                                 . . . .
. . . .
                                 Enoki Ramirez! Euh... Maintenant Tremblay, c'est ça? Merci beaucoup de m'avoir permis de venir ici.
                                 Je promets que je ne causerait aucun problème ici, bien que mes derniers clients...

                                 Écoute, ce n'était pas MA faute si j'étais si doué pour faire semblant d'être un avocat de haut niveau, tu connais?

                                 Je sais que tu me comprends. Faites-moi savoir s'ils viennent me chercher pour que je puisse me cacher à temps. Bien?
                                 Mon rêve depuis que je suis enfant est d'être commerçant dans une petite ville, même si je n'ai pas grand-chose à vendre.
                                 Maintenant que j'en ai l'opportunité, je ferai de mon mieux! Comment puis-je vous aider aujourd'hui?
                                 . . . .

Chapter Four intro

RUFUS                            Good evening, everyone.          It seems as if my warning was    not enough for you, as no one   
RUFUS                            has shown even the tiniest hint  of fear over the past month.     This is a dreadful mistake,      for you see, I have concocted a 
RUFUS                            plan to overwhelm your defenses  and take your island for         myself.
MAPLE                            ...Ugggh, shut up, Rufus, I'm    trying to sleep.
RUFUS                            I have developed a-
ENOKI                            I don't remember turning the     TV on this morning, you do       that, Maple?
MAPLE                            ...
AARON                            Maybe I accidentally pushed      something. Should I turn it      off?
MAPLE                            ...mmmrff... tv... turn          off... saturday...
RUFUS                            In exactly T-Minus thirty        seconds, I will unleash my-

AARON                            Okay, it's off now.
ENOKI                            What's he always on about?
AARON                            I don't know, Noke.
MAPLE                            ...
ENOKI                            Hey, what's that noise?
AARON                            I don't like that, it sounds     like... Hey, Maple, maybe you    should get up.
MAPLE                            ...grr, I'm gonna kill that      gator...
ENOKI                            What the- oh no..
AARON                            Enoki, you and Maple go to       Scout's bunker, I'm going to     check on everyone out west.
MAPLE                            Excusez-moi, I can take care     of-
AARON                            You go to the bunker and get     some more sleep.
MAPLE                            Hey, no need to be               passive-aggressive about it.

RUFUS                            Buenas tardes a todos. Parece    que mi anterior advertencia no   fue suficiente y nadie
RUFUS                            ha mostrado ni el más mínimo     indicio de miedo durante el      último mes. Habéis cometido un   grave error, ya que
RUFUS                            planeo tomar la isla a la        fuerza si es necesario.
MAPLE                            ...Ugggh, cállate, Rufus,        Intento dormir.
RUFUS                            He desarrollado un-
ENOKI                            No recuerdo haber encendido la   tele esta mañana,                ¿la has encendido tú, Maple?
MAPLE                            ...
AARON                            Tal vez haya pulsado algo por    accidente. ¿La apago?
MAPLE                            ...mmmrff... tele... apagada...  sábado...
RUFUS                            En menos de treinta segundos     liberaré mi-
RUFUS                            Bonjour à tous. Il semble que mon avertissement précédent n'était pas suffisant et personne
RUFUS                            n'a pas montré le moindre soupçon de peur au cours du mois dernier. vous autres avez fait une grave erreur, car je prévois de prendre l'île par la force si nécessaire.
MAPLE                            ...Ugggh, tais-toi, Rufus, j'essaie de dormir.
RUFUS                            J'ai développé un-
ENOKI                            Je ne me souviens pas d'avoir allumé la télé ce matin, tu l'as allumé, Maple?
MAPLE                            ...
AARON                            J'ai peut-être heurté quelque chose par accident. Est-ce que je l'éteins?
MAPLE                            ...mmmrff... TV... off... Samedi...
RUFUS                            Dans moins de trente secondes, je lâcherai mon-

AARON                            Okay, se acabó.
ENOKI                            ¿De qué iba todo eso?
AARON                            Ni idea, Noke.
MAPLE                            ...
ENOKI                            Hey, ¿qué es ese ruido?
AARON                            No me gusta cómo suena eso...    Maple, quizá deberías levantarte.
MAPLE                            ... Grr, Voy a cargarme a ese    caimán...
ENOKI                            Pero qué- oh no...
AARON                            Enoki, tú y Maple corred hace el búnker de Scout, yo iré al oeste para ver si los demás están bien.
MAPLE                            Excusez-moi, puedo cuidar de mi-
AARON                            Vas a ir al búnker, además allí  podrías seguir durmiendo.
MAPLE                            Hey, no hay necesidad de ser tan pasivo-agresivo conmigo.
AARON                            D'accord, c'est fini.
ENOKI                            De quoi s'agissait-il?
AARON                            Aucune idée, Noke.
MAPLE                            ...
ENOKI                            Hé, c'est quoi ce bruit?
AARON                            Je n'aime pas le son de ça... Maple, tu devrais peut-être te lever.
MAPLE                            ...Grr, je vais tuer cet alligator...
ENOKI                            Mais quoi- oh non...
AARON                            Enoki, toi et Maple cours au bunker de Scout, je vais vers l'ouest pour voir si les autres vont bien.
MAPLE                            Excusez-moi, je peux m'occuper de mon-
AARON                            Tu vas aller au bunker, en plus tu pourras still y dormir.
MAPLE                            Hé, pas besoin d'être aussi passif-agressif avec moi.
Dialogue when Maple and Scout are trying to get through the underground minigame

MAPLE                            So come clean with me, oui?      Did you make this place?
SCOUT                            Heck no! I kind of wish I did,   though.
SCOUT                            MAPLE LOOK OUT!
MAPLE                            ...Scout, are you alright?
RUFUS                            Ow. I think it popped my back a  bit, though.
MAPLE                            What's with all the gasoline in  this place, huh?
SCOUT                            Maybe be a little extra careful  with that fire power of yours in this next part, huh?

MAPLE                            ...
MAPLE                            What... the actual heck am I     looking at right now?
RUFUS                            Ichabod Williams and             Maple Tremblay, what a surprise! Fancy seeing you two here.
RUFUS                            Finally, I've got a full set.
SCOUT                            RUFUS THI-, WHAT ARE YOU DOING?
MAPLE                            LET ME GO, YOU PUNK!
RUFUS                            I suppose it won't be a bad idea to clap a magic-proof wristband  to keep you from getting any...  sparks of inspiration.
RUFUS                            Alright, now that we've got all  three Tremblays in one place,    let's get started, shall we?
RUFUS                            Firstly, let's have an           short introduction. I'm Monsieur Rufus Thibodeaux, and I'm going  to be your professor today.
RUFUS                            Pay attention - no one ever seemsto pay attention to  me, so therewill definitely be a quiz at the end of today's lecture.
RUFUS                            Lesson one. Repeat after me,     'Rufus is not short. He is just  small-boned.'
MAPLE                            .....Are you kidding me?
RUFUS                            That doesn't sound very much likethe prompt, does it, Maple?
RUFUS                            Everyone fails that section.     Moving on... Let's talk about theApres Flower. I was employed by  a certain company to
RUFUS                            study this flower - same as our  dear Ichabod.. er.. 'Scout',     here. If you remember, it's both native here and known
RUFUS                            to contain unknown 'metaphysical'properties. Neat, huh? So,       despite my instructions, I felt  bored and decided to
RUFUS                            have myself a little chompy-chompof some of the leaves. Do you    know what happened after that?
RUFUS                            Within moments, I found myself   traveling through the multiverse.I explored all sorts of differentworlds, some similar
RUFUS                            and others very different to     ours, but do you know what I     discovered in nearly every one?
RUFUS                            There was this strange trend of  strong-willed, conventionally    attractive women who seemed to   act as the moral good
RUFUS                            and savior of every world, with  strange-looking men serving as   the butt of every joke, or as    incompetant villains
RUFUS                            only to be replaced by the much  more competant, misunderstood    female villains who were only badbecause a man somehow
RUFUS                            turned them evil. And you know   what I thought?
MAPLE                            Hold on-
MAPLE                            Are you literally telling me thatyou've decided to become a super villain because you took a flowerthat told you that
MAPLE                            you're the 'bad guy'?
RUFUS                            I believe that by taking a pre-  emptive strike, I can manage to  keep my respect and autonomy     short intact, yes.
RUFUS                            You see, I believe Maple is the  'main character' based on her    attributes, so I figured it was  best to plan like this.
ENOKI                            Monsieur Rufus, may I go to the  restroom?
RUFUS                            You can go after the lecture, I'malmost done.
RUFUS                            Now, as I was saying....
AARON                            Rufus, let's have a talk.
AARON                            First off, I'm surprised you     didn't know my wife was a        magician, she's good at getting  out of tight spaces.
AARON                            Secondly, I don't care what you  saw when you ate that flower, youscared a lot of my friends. Bad.
AARON                            That's completely unacceptable.  You can't just kidnap people and hold them hostage.
AARON                            Let us go and leave us alone,    c'est bon? Got it?
RUFUS                            Just hold on a moment, Aaron.
RUFUS                            There's something you should knowThe doors to this room are       completely, hopelessly tightly   sealed.
RUFUS                            A bomb could go off outside and  we'd barely notice. However, the moment one of y'all takes a      little bit of Apres flower,
RUFUS                            those doors open wide up. Here's my challenge. We have a little   fight. If you win, I leave your  island alone.
RUFUS                            I win, and I get to be the new   king. Either way, you gotta take the Apres to get out. Oui?
RUFUS                            I'm confident that once one of   you sees the things I'll see, I  won't seem nearly as crazy.
RUFUS                            We'll see.
RUFUS                            Well, well, well...
RUFUS                            HA! Looks like I'm the victor    here. It's Apres flower time.
RUFUS                            So, who will it be? Aaron, how   about you give it a go?
MAPLE                            You know what? In your dreams,   you little punk.
RUFUS                            W-Who you calling little?
MAPLE                            For one, even your little robot  legs are standing on their       tiptoes.
MAPLE                            Look, I don't know why you're    obsessed with thinking the world is like your flower-induced      fever dream.
MAPLE                            But life is complicated, alright?Everybody's complicated. I don't care what you saw in that flower,but you can't just
MAPLE                            come in and harrass us on our ownisland. We didn't even know who  you were, dude.
MAPLE                            I'll threaten you again like I   threaten everybody else-         any funny business, and-
RUFUS                            I-I know, I know, I know, you'll burn my face off.
RUFUS                            Hey, uh, be careful with that    fire, it's, uh, I've got a lot offlamables down here.
MAPLE                            CAREFUL? After you KIDNAP us?    You're darn straight I'll burn   your face off.
CESAR                            Hey, Maple?
MAPLE                            NOT NOW CESAR, I'M MESSING WITH ALITTLE MEGALOMANIAC, HERE!
RUFUS                            N-No seriously, you, er, uh..    Oh dear..
MAPLE                            WHAT?! 

MAPLE                            Dime la verdad, ¿oui?            ¿Tú hiciste todo este lugar?
SCOUT                            ¡Imposible! Aunque me habría     gustado conseguirlo por mí mismo.
SCOUT                            ¡MAPLE, CUIDADO!
MAPLE                            ... Scout, ¿te encuentras bien?
RUFUS                            Ow. Aunque me golpeé un poco la  espalda. Creo que estaré bien.
MAPLE                            ¿Qué hace toda esta gasolina     en este sitio?
SCOUT                            Por nuestro bien, más te vale    tener cuidado con tus poderes.
MAPLE                            Dis-moi la vérité, oui? C'est toi qui a fait tout cet endroit?
SCOUT                            Impossible! Bien que j'aurais aimé l'obtenir moi-même.
SCOUT                            MAPLE, ATTENTION!
MAPLE                            ... Scout, tu vas bien?
RUFUS                            Aïe. Même si je me suis un peu cogné le dos. Je pense que ça ira.
MAPLE                            Qu'est-ce que toute cette gasoline fait ici?
SCOUT                            Pour notre bien, vous feriez mieux d'être prudent avec vos pouvoirs.

MAPLE                            ...
MAPLE                            Qué... ¿Qué diantes estoy viendo ahora mismo?
RUFUS                            Ichabod Williams y               Maple Tremblay, ¡Qué sorpresa!   Me alegra veros por aquí.
RUFUS                            Al fin hemos podido reunirnos    todos.
SCOUT                            RUFUS QU-, ¿QUÉ ESTÁS HACIENDO?
MAPLE                            ¡DÉJAME EN PAZ, IMBÉCIL!
RUFUS                            Será mejor que te ponga una      pulsera anti-magia para evitar   que te dé una de esas...         Chispas de inspiración
RUFUS                            Muy bien, ahora que tenemos a    todos los Tremblay  reunidos en un mismo  lugar...                ¡Podemos comenzar!
RUFUS                            En primer lugar, hagamos una     breve introducción. Soy Monsieur Rufus Thibodeaux, y hoy seré     vuestro profesor.
RUFUS                            Prestad atención.  Nadie parece  hacerme caso, así que            haremos un examen al final       de la sesión.
RUFUS                            Lección número uno. Repetid      conmigo, 'Rufus no es bajo. Sólo tiene huesos pequeños.'
MAPLE                            ..... ¿Estás de guasa?
RUFUS                            Eso no se parece mucho a la fraseque tienes que decir ahora,      ¿no, Maple?
RUFUS                            Parece que todos están fallado   esta lección. Así que pasemos a  la siguiente... Hablemos de la flor Apres. Una compañía
RUFUS                            me contrató para estudiarla. Al  igual que Ichabod... o 'Scout',  un chico nativo y conocido por   todos los de la isla.
RUFUS                            Las 'propiedades metafísicas’ de las flor son bien chulas, así    que a pesar de que las           instrucciones decían 
RUFUS                            que no debía hacerlo. Un día me  aburrí y decidí darle unos       mordisquitos. ¿Y sabéis lo que   pasó después de eso?
RUFUS                            Me encontré viajando a través delmultiverso. Exploré todo tipo de mundos diferentes, algunos       similares a este
RUFUS                            y otros completamente alejados deesta realidad. ¿Pero sabéis lo   que descubrí en casi cada uno de ellos?
RUFUS                            Había una extraña tendencia de   mujeres convencionalmente        atractivas que luchaban contra elmal de esos mundos.
RUFUS                            Junto a extravagantes hombres    que servían como blanco  de todaslas bromas o actuando como       incompetentes villanos.
RUFUS                            Al final todos ellos eran        reemplazados por villanas más    competentes e incomprendidas que eran malvadas porque
RUFUS                            los hombres las volvieron así.   ¿Podéis adivinar qué pensé en    esos momentos?
MAPLE                            Para el carro, colega.
MAPLE                            ¿Me estás diciendo de verdad que te has vuelto malvado por el     simple hecho de que una flor     te dijo
MAPLE                            que eres el 'chico malo'?
RUFUS                            Creo que con un ataque            preventivo, puedo mantener      intactas tanto mi imagen como mi autonomía. Sí.
RUFUS                            Desde mi punto de vista y habiendoestudiado sus atributos, Maple  parece el 'personaje principal' yeste fue mi mejor plan.
ENOKI                            Monsieur Rufus, ¿puedo ir al baño?
RUFUS                            Podrás ir después de la lección. Casi he terminado.
RUFUS                            A ver, ¿por dónde iba...?
AARON                            Rufus, tenemos que hablar.
AARON                            En primer lugar. Me sorprende    que no supieras que mi esposa es maga. Además se le da bien huir  por espacios reducidos.
AARON                            Y en segundo lugar. Me da igual  las majaderías que viste con esa flor, asustaste a todos mis      amigos. Chico malo.
AARON                            Eso es totalmente inaceptable.   No puedes secuestrar a la gente ymantenerla como rehenes.
AARON                            Suéltanos y déjanos en paz,      ¿c'est bon? ¿Lo captas o no?
RUFUS                            Espera un momento, Aaron.
RUFUS                            Hay algo que deberías saber. Las puertas de esta habitación están selladas herméticamente.
RUFUS                            Si una bomba estallara fuera     apenas nos daríamos cuenta aquí  dentro. Aunque las puertas       se abrirían...
RUFUS                            Si alguien prueba la flor. Así   que os desafío. Si lográis       superar este entuerto, dejaré    vuestra isla en paz.
RUFUS                            Si yo gano, me convertiré en el  nuevo rey. ¿Aunque tendréis el   valor suficiente como para tomar la flor? ¿Oui?
RUFUS                            Una vez alguno de ustedes        llegue a ver todo lo que yo he   visto, dejaréis de tomarme       como a un loco.
RUFUS                            Ya veremos qué ocurre...
RUFUS                            Bueno, bueno, bueno...
RUFUS                            ¡HA! ¡Parece que me llevo la     victoria! ¡Es hora de usar la    flor Apres!
RUFUS                            Así que... ¿Quién la probará?    ¿Aaron? ¿Qué te parece si le das una probadita?
MAPLE                            ¿Sabes qué? Ni en tus sueños,    pequeñajo revoltoso.
RUFUS                            ¿A-a quién le dices pequeñajo?
MAPLE                            Incluso tus pequeñas piernas     robóticas se mantienen sobre las puntillas de sus pies.
MAPLE                            No sé por qué estás obsesionado  con pensar que el mundo es como  tu sueño febril inducido         por las flores.
MAPLE                            Pero la vida es difícil, ¿sabes? Y bastante tenemos lidiando con  nuestros problemas. Me da igual  lo que viste en tus sueños, 
MAPLE                            no hubieras venido a molestarnos a nuestra propia isla.           Ni siquiera hubiésemos sabido    quién demonios eres.
MAPLE                            así que volveré a amenazarte de  nuevo como amenazo a todos los   demás. Cómo sigas tocándome los  ovarios, vas a ver-
RUFUS                            L-lo sé, lo sé, ya lo dijiste,   harás una barbacoa con mi cara.
RUFUS                            Aunque, uh, te cuidado con eso   del fuego. Hay muchos objetos    inflamables aquí abajo.
MAPLE                            ¿CUIDADO? ¿Dices que tenga       cuidado después de SECUESTRARNOS?Al final te lo has buscado, ¡tu  cara va a salir ardiendo!
CESAR                            Hey, ¿Maple?
MAPLE                            AHORA NO CÉSAR, ¡DEBO OCUPARME   DE ESTE PEQUEÑO MEGALÓMANO!
RUFUS                            N-No en serio, tú, er, uh...     Madre mía...
MAPLE                            ¡¿QUÉ?! 
MAPLE                            ...
MAPLE                            Quoi... Quelles dents je regarde en ce moment?
RUFUS                            Ichabod Williams et Maple Tremblay, Quelle surprise! Je suis content de vous autres voir ici.
RUFUS                            Enfin, nous-autres avons tous pu nous-autres rencontrer.
SCOUT                            RUFUS Qu-, QU'EST-CE QUE TU FAIS?
MAPLE                            LAISSEZ-MOI TRANQUILLE, ENFANT!
RUFUS                            Tu ferais mieux de mettre un bracelet anti-magie sur toi pour éviter d'en avoir un... Des étincelles d'inspiration
RUFUS                            Bon, maintenant que nous-autres avons tous les Tremblay réunis au même endroit... nous-autres pouvons commencer!
RUFUS                            Tout d'abord, faisons une brève introduction. Je suis Monsieur Rufus Thibodeaux, et aujourd'hui je serai votre professeur.
RUFUS                            Faites attention. Personne ne semble m'écouter, alors nous-autres ferons un quiz à la fin de la séance.
RUFUS                            Leçon numéro un. Répétez après moi, 'Rufus n'est pas petit. Il n'a que de petits os.
MAPLE                            .....Vous plaisantez?
RUFUS                            Ça ne ressemble pas beaucoup à la phrase que tu as à dire maintenant, n'est-ce pas, Maple?
RUFUS                            Il semble que tout le monde échoue cette leçon. Alors passons au suivant... Parlons de la fleur d'Apres. Une entreprise m'a engagé pour l'étudier. Tout comme Ichabod... ou 'Scout', un garçon autochtone connu de tous sur l'île.
RUFUS                            Les "propriétés métaphysiques" des fleurs sont plutôt cool, donc même si les instructions disaient
 qu'il ne devrait pas. Un jour, je me suis ennuyé et j'ai décidé de prendre quelques bouchées. Et savez-vous ce qui s'est passé ensuite?
RUFUS                            Je me suis retrouvé à voyager à travers le multivers. J'ai exploré toutes sortes de mondes différents, certains similaires à celui-ci et d'autres complètement éloignés de cette réalité. Mais savez-vous ce que j'ai découvert dans presque chacun d'entre eux?
RUFUS                            Il y avait une tendance étrange de femmes attirantes conventionnelles combattant le mal de ces mondes.
RUFUS                            Avec des hommes flamboyants qui ont servi de cible à toutes les blagues ou ont agi comme des méchants incompétents.
RUFUS                            À la fin, ils ont tous été remplacés par des méchants plus compétents et incompris qui étoint mauvais parce que les hommes les avaient créés ainsi. Pouvez-vous deviner ce que je pensais à ce moment-là?
MAPLE                            Arrête la voiture, mec.
MAPLE                            Es-tu vraiment en train de me dire que tu es devenu méchant simplement parce qu'une fleur t'a dit
MAPLE                            tu es le 'méchant'?
RUFUS                            Je crois qu'avec une frappe préventive, je peux garder intacte mon image et mon autonomie. Oui.
RUFUS                            De mon point de vue et après avoir étudié ses attributs, Maple ressemble au "personnage principal" et c'était mon meilleur plan.
ENOKI                            Monsieur Rufus, puis-je aller aux toilettes?
RUFUS                            Vous pouvez y aller après la leçon. J'ai presque fini.
RUFUS                            Voyons, où allait-il...?
AARON                            Rufus, nous-autres devons parler.
AARON                            Tout d'abord. Je suis surpris que vous ne sachiez pas que ma femme est magicienne. Il est également bon pour s'échapper à travers des espaces restreints.
AARON                            Et deuxièmement. Je me fiche de ce que tu as vu avec cette fleur, tu as effrayé tous mes amis. Un mauvais garçon.
AARON                            C'est totalement inacceptable. Vous ne pouvez pas kidnapper des gens et les garder en otage.
AARON                            Lâche-nous et laisse-nous tranquille, c'est bon? Comprenez-vous ou non?
RUFUS                            Attendez une minute, Aaron.
RUFUS                            Il y a quelque chose que tu dois savoir. Les portes de cette pièce sont hermétiquement fermées.
RUFUS                            Si une bombe explosait à l'extérieur, nous-autres la remarquons à peine ici. Bien que les portes s'ouvriront...
RUFUS                            Si quelqu'un goûte la fleur. Alors je vous mets au défi. Si vous parvenez à surmonter ce gâchis, je laisserai votre île en paix.
RUFUS                            Si je gagne, je deviendrai le nouveau roi. Bien que vous aurez le courage de prendre la fleur? Oui?
RUFUS                            Une fois que l'un d'entre vous aura vu tout ce que j'ai vu, vous cesserez de me prendre pour un imbécile.
RUFUS                            Nous verrons ce qui se passera...
RUFUS                            Bien, bien, bien...
RUFUS                            HA! On dirait que je gagne! C'est le moment d'utiliser la fleur d'Apres!
RUFUS                            Alors... qui va le goûter? Aaron? Que pensez-vous si vous lui donnez un peu de goût?
MAPLE                            Vous savez quoi? Même pas dans tes rêves, petit exubérant.
RUFUS                            Qui appelles-tu petit gars?
MAPLE                            Même vos petites jambes robotiques restent sur la pointe de leurs pieds.
MAPLE                            Je ne sais pas pourquoi tu es obsédé par l'idée que le monde est comme ton rêve de fièvre induite par les fleurs.
MAPLE                            Mais la vie est dure, tu connais? Et nous-autres en avons assez de gérer nos problèmes. Je me fiche de ce que tu as vu dans tes rêves, tu ne serais pas venu nous-autres déranger sur notre propre île. On n'aurait même pas su qui tu es.
MAPLE                            donc je vais te menacer à nouveau comme je menace tout le monde. Comment continuez-vous à toucher mes ovaires, vous allez voir-
RUFUS                            Je-je sais, je sais, tu l'as déjà dit, tu vas me griller le visage.
RUFUS                            Bien que, euh, fais attention au feu. Il y a beaucoup d'objets inflammables ici.
MAPLE                            FAIS ATTENTION? Tu dis de faire attention après nous-autres avoir KIDNAPPÉS? Finalement, tu lui as demandé, ton visage va brûler!
CESAR                            Hé, Maple?
MAPLE                            NO NO CAESAR, JE DOIS PRENDRE SOIN DE CE COUILLON PETIT!
RUFUS                            N-Pas vraiment, toi, euh, euh... Mon Dieu...
MAPLE                            QUOI?!
Outside cutscene on the boat with Guy and Diana

GUY                              It's nice out here.
DIANA                            You're telling me. Honestly if itwasn't so expensive, I'd just    boat around 24/7.
GUY                              You think we gonna get any       tourists?
DIANA                            Okay, I don't know if this is    just you, but you need to chill  out about your restaraunt.
DIANA                            You need to learn when to take a break and relax, oui?
GUY                              I guess so. It's like my baby    though. I'm crazy about it.
DIANA                            I mean, what if something        happened, though? Like, what if  it blew up?
GUY                              ...
DIANA                            ...
GUY                              Thunder... my... dog.

RUFUS                            What the...
RUFUS                            ...
MAPLE                            I... I-I...
AARON                            Maple, I-
MAPLE                            ...I-I'm...
ENOKI                            Maple, come back!
MAPLE                            ...
AARON                            Maple, get up.
MAPLE                            ...
AARON                            Maple, we need to talk.          Right now.
ENOKI                            Maple, it's-
AARON                            Maria, I love you, but it needs  to just be Maple and I.
ENOKI                            Maria...
ENOKI                            A-Alright, I'll go check on the others.
AARON                            Maple. We've needed to have this talk for a very long time and it can't wait.
AARON                            I think you know what it's about.
MAPLE                            I d-don't want to talk right now.
AARON                            I wanted to apologize.
AARON                            I've been complaining about you  behind your back to the others.
AARON                            You've done so much that has mademe proud to be your big brother.
AARON                            But you... you've got this anger inside of you all of the time at everything you percieve to be    wrong with the world.
AARON                            Anger isn't a bad thing, but     everything you're angry about..  it's because you see it in       yourself, too.
AARON                            I appreciate that you stood up   for me.
MAPLE                            Shut up.
AARON                            Not right now.
AARON                            Take your time to calm down, but you will learn to take care of   your anger, or I can't help you  anymore, oui?
MAPLE                            ...Oui.
AARON                            That's what I thought.           Rufus, I believe I have a deal totake care of.
ENOKI                            A-Aar.. AARON, WAIT!
AARON                            We need to get those doors open.
RUFUS                            Hey, I can find a way to disable the door, I'm sure of it, a-at   least.. I think, you don't need  to-
AARON                            I'm doing it.
                                 N-No... I can't lose you...
                                 A-Aaron?                         Why are you looking at me        like that?
                                 Say something already..          You're scaring me..
AARON                            I paid off the island in cash. Weshould easily have enough to renta house back in Louisiana.
AARON                            A cajun isn't home outside of    Louisiana anyway, oui?
AARON                            I should have enough to give you all a few months' rent wherever  you want to live as you return tonormal life.
AARON                            I want to say that I was proud tobe your king while it lasted.    Thank you all.
OLIVIER                          No, thank you too. I don't know  what Eleanor and I will do, but..we will think of something.
OLIVIER                          We all came here because we      didn't have any money anyway.    Meeting y'all has been           a blessing.
CESAR                            And Enoki definitely saved my    butt, no doubt about it.
RUFUS                            I-I can help if anyone needs     anything or anywhere to stay. I'mreally, really sorry about       y'all's island.
RUFUS                            I never meant to actually cause  any problems, I was just here to mildly antagonize y'all, I..     Geez..
RUFUS                            Hey, I've got blankets and stuff if you need a place to sleep for the night.
AARON                            ...Thank you, Rufus.
AARON                            We all need some time to process what just happened. I didn't see Diana's boat in the island       footage.
AARON                            Everyone seems to have been okay,and that's what matters most.
AARON                            I love you all.

SCOUT                            Maple, how are you doing?
MAPLE                            ...
MAPLE                            ...Don't you dare give me any    pity, are we clear?
SCOUT                            Y-Yeah, of course, I just.. I'm  sorry for-
MAPLE                            What are YOU sorry for?
SCOUT                            Please just let me finish.
MAPLE                            Fine. Go on.
SCOUT                            I.. I'm sorry for being forward, but please don't beat yourself   up. I'm on your side, right?
MAPLE                            What, are you going to ask me outor something?
SCOUT                            No, I- I.. well, no, I wasn't    going to.. look, I just don't    want you to go.
SCOUT                            We're not mad at you, and.. look,I don't want to lose your        friendship because you're
SCOUT                            mad at yourself, okay? You're    more important than that island. I...
SCOUT                            Just promise me that you won't   go anywhere or do anything stupidbecause of this. Please.
MAPLE                            ...
MAPLE                            ...I won't, Scout. Don't worry.
ENOKI                            Hey, Maple! Back home so early?
MAPLE                            Yep. The interview went great.   The military is going to suck,   but... the benefits are nice.
AARON                            You're gonna do great, Maple.
MAPLE                            You really think so?
AARON                            You'll be the only elf on the    team, I bet. That's a huge       advantage.
MAPLE                            Yeah, I guess so. I talked to    Scout about it, he's happy enoughbut he says he'll miss me.
ENOKI                            We will too.
ENOKI                            Well, Aaron and I, we've got somenews, too.
MAPLE                            Oh dear, what?
ENOKI                            It's looking like we.. uh.. theremight be another Tremblay here   soon enough.
MAPLE                            Hold on, you're not-?
ENOKI                            Uh huh!
MAPLE                            You're... PREGNANT?
AARON                            Yes, ma'am.
MAPLE                            Holy cow, I-.. I'm gonna be an   aunt. An Aaron-Enoki mix, what's that even going to be like?
ENOKI                            2000 has been such a great year, I bet 2001 will be even better!
AARON                            Whatever adventure it turns out  to be like, I'm just glad y'all  are here for it.
MAPLE                            Happy 2001, y'all.
ENOKI                            Happy 2001.

GUY                              Se siente bien aquí fuera.
DIANA                            Y que lo digas. Si navegar no    fuese tan caro lo haría todo     el tiempo.
GUY                              ¿Crees que vendrán más turistas  a la isla?
DIANA                            Deberías relajarte un poquito    con todo el tema de tu           restaurante.
DIANA                            Aprende a tomar un descanso y    relajarte de vez en cuando, ¿oui?
GUY                              Supongo que debería. Pero la     cocina es como si fuera mi bebé, no puedo evitarlo.
DIANA                            ¿Y si algo le pasara? ¿Y si      un día estallara de repente?
GUY                              ...
DIANA                            ...
GUY                              Santo... Cielo...

RUFUS                            Pero qué...
RUFUS                            ...
MAPLE                            Yo... Y-Yo...
AARON                            Maple, Yo-
MAPLE                            ...Yo-Estoy...
ENOKI                            ¡Maple, ven aquí!
MAPLE                            ...
AARON                            Maple, levántate.
MAPLE                            ...
AARON                            Maple, tenemos que hablar.       Ahora mismo.
ENOKI                            Maple, es-
AARON                            Maria, te amo, pero Maple y yo   tenemos que hablar.
ENOKI                            Maria...
ENOKI                            V-Vale, iré a ver cómo están los demás.
AARON                            Maple. Hemos necesitado tener    esta charla desde hace mucho     tiempo, y ya no puedo esperar    más.
AARON                            Creo que sabes de qué se trata.
MAPLE                            N-no me apetece hablar           ahora mismo.
AARON                            Quiero disculparme contigo.
AARON                            Me he estado quejando de ti a tusespaldas con los demás.
AARON                            Aunque al final has hecho un     montón de cosas que hacen que me sienta orgulloso de ser tu       hermano mayor.
AARON                            Tienes esa ira que está todo el  tiempo dentro de ti, una ira que proyectas hacia todo lo que ves  mal de este mundo.
AARON                            La ira no es algo malo, pero     ahora entiendo que te ves        reflejada en todo aquello que    te hace enfadar.
AARON                            Gracias por todo, agradezco muchoque me defendieras.
MAPLE                            Cállate.
AARON                            No me voy a callar.
AARON                            Tómate tu tiempo para calmarte,  pero tendrás que aprender a      controlar tu ira. O no podré     seguir apoyándote.
MAPLE                            ...Oui.
AARON                            Me alegra que lo entiendas.      Rufus, Creo que también tenemos  algo de lo que hablar.
ENOKI                            A-Aar.. AARON, ¡UN MOMENTO!
AARON                            Necesitamos abrir esas puertas.
RUFUS                            Hey, estoy seguro de que puedo   encontrar una forma de desactivar el cierre. Creo que no tienes    por qué-
AARON                            Yo lo haré.
                                 N-No... No puedo perderte...
                                 ¿A-Aaron?                        ¿Por qué me miras de esa forma?        
                                 Di algo...                       Me estás asustando...
AARON                            Pagué la isla en efectivo.       Deberíamos tener lo suficiente   como para alquilarnos una casa   en Louisiana.
AARON                            De todas formas, un cajún nunca  encontrará un mejor hogar fuera  de Louisiana , ¿oui?
AARON                            Creo que tengo suficiente dinero para pagarles a todos unos meses de alquiler hasta que puedan     volver a sus vidas normales.
AARON                            Quiero decir que para mí ha sido un orgullo ser vuestro rey       durante este tiempo. Gracias a   todos por estar ahí.
OLIVIER                          También queremos darte las       gracias. No sé qué haremos yo y  Eleanor, pero... Ya pensaremos   en algo.
OLIVIER                          Vinimos aquí porque no           teníamos recursos. Así que       conocerlos a todos ha sido una   bendición.
CESAR                            Y no hay duda de que Enoki me    salvó el trasero.
RUFUS                            P-puedo ayudaros si alguno me    necesita o le hace falta un lugardonde quedarse. Lamento mucho lo de vuestra isla...
RUFUS                            En realidad nunca quise causar   tantos problemas, sólo estaba     aquí para hacer un poco de      antagonista, yo...
RUFUS                            Oye, tengo mantas y cosas así    por si necesitan quedarse para    pasar la noche.
AARON                            ...Gracias, Rufus.
AARON                            Todos necesitaremos un tiempo    para procesar lo ocurrido. Aunque no vi el barco de Diana en el   metraje de la isla.
AARON                            Todo el mundo parece estar bien. Y al fin y al cabo, eso es lo más importante de todo.
AARON                            Os aprecio muchísimo.
GUY                              Ça fait du bien ici.
DIANA                            Et tu le dis. Si la voile n'était pas si chère, je le ferais tout le temps.
GUY                              Penses-tu que plus de touristes viendront sur l'île?
DIANA                            Tu devrais te détendre un peu avec tout le thème de ton restaurant.
DIANA                            Apprendre à faire une pause et à se détendre de temps en temps, non?
GUY                              Je suppose que je devrais. Mais la cuisine est comme mon bébé, je ne peux pas m'en empêcher.
DIANA                            Et s'il lui arrivait quelque chose? Et si un jour il éclatait soudainement?
GUY                              ...
DIANA                            ...
GUY                              ...Mais.

RUFUS                            Mais quoi...
RUFUS                            ...
MAPLE                            Je... je-je...
AARON                            Maple, je-
MAPLE                            ... je-je suis...
ENOKI                            Maple, viens ici!
MAPLE                            ...
AARON                            Maple, lève-toi.
MAPLE                            ...
AARON                            Maple, nous-autres devons parler. Maintenant même.
ENOKI                            Maple, est-
AARON                            Maria, je t'aime, mais Maple et moi devons parler.
ENOKI                            Maria...
ENOKI                            V-D'accord, je vais voir comment vont les autres.
AARON                            Maple. Nous avions besoin d'avoir cette conversation depuis longtemps, et je ne peux plus attendre.
AARON                            Je pense que tu sais de quoi il s'agit.
MAPLE                            Je-je n'ai pas envie de parler en ce moment.
AARON                            Je veux te présenter mes excuses.
AARON                            Je me suis plaint de toi dans ton dos aux autres.
AARON                            Bien qu'au final tu aies fait beaucoup de choses qui me rendent fier d'être ton grand frère.
AARON                            Tu as cette colère qui est en toi tout le temps, une colère que tu projettes vers tout ce que tu vois comme mauvais dans ce monde.
AARON                            La colère n'est pas une mauvaise chose, mais maintenant je comprends que tu vois reflété dans tout ce qui te met en colère.
AARON                            Merci pour tout, j'apprécie vraiment que tu me défendes.
MAPLE                            Tais-toi.
AARON                            Je ne vais pas me taire.
AARON                            Prends ton temps pour te calmer, mais tu devras apprendre à contrôler ta colère. Ou je ne pourrai plus te soutenir.
MAPLE                            ...Oui.
AARON                            Je suis content que tu comprennes. Rufus, je pense que nous-autres avons aussi quelque chose à nous-autres dire.
ENOKI                            A-Aar.. AARON, ATTENDS!
AARON                            Nous devons ouvrir ces portes.
RUFUS                            Hé, je suis sûr que je peux trouver un moyen de désactiver le verrou. Je pense que tu n'as pas à-
AARON                            Je le ferai.
                                 N-Non... je ne peux pas te perdre...
                                 A-Aaron? Pourquoi me regardes-tu ainsi?
                                 Dis quelque chose... tu me fais peur...
AARON                            J'ai payé l'île en espèces. Nous devrions en avoir assez pour louer une maison en Louisiane.
AARON                            Un acadien ne trouvera jamais une meilleure maison en dehors de la Louisiane de toute façon, oui?
AARON                            Je pense que j'ai assez d'argent pour payer à tout le monde quelques mois de loyer jusqu'à ce qu'ils puissent reprendre une vie normale.
AARON                            Je veux dire que ce fut un honneur pour moi d'être votre roi pendant cette période. Merci à tous d'être là.
OLIVIER                          Nous tenons également à vous autres remercier. Je ne sais pas ce que moi et Eleanor allons faire, mais... On trouvera quelque chose.
OLIVIER                          Nous sommes venus ici parce que nous-autres n'avions pas de ressources. Donc vous autres rencontrer tous a été une bénédiction.
CÉSAR                            Et il ne fait aucun doute que Enoki m'a sauvé la mise.
RUFUS                            Je... Je peux t'aider si quelqu'un a besoin de moi ou a besoin d'un logement. Je suis vraiment désolé pour votre île...
RUFUS                            Je n'ai jamais vraiment voulu causer autant de problèmes, j'étais juste ici pour jouer un peu l'antagoniste, je...
RUFUS                            Hé, j'ai des couvertures et des trucs si tu as besoin de passer la nuit.
AARON                            ...Merci, Rufus.
AARON                            Nous aurons tous besoin de temps pour assimiler ce qui s'est passé. Je n'ai cependant pas vu le bateau de Diana sur les images de l'île.
AARON                            Tout le monde semble bien. Et à la fin, c'est la chose la plus importante de toutes.
AARON                            Je t'apprécie beaucoup.

SCOUT                            Maple, ¿cómo lo llevas?
MAPLE                            ...
MAPLE                            ... No te atrevas a preocuparte  por mí. ¿Queda claro?
SCOUT                            S-sí, clarísimo, Es sólo que...  Lo siento por-
MAPLE                            ¿Qué es lo que SIENTES tanto?
SCOUT                            Déjame terminar.
MAPLE                            Bien. Continúa.
SCOUT                            Perdona por ser atrevido, pero   por favor, deja de culparte      tanto. Estoy de tu lado, ¿sabes?
MAPLE                            Qué, ¿me vas a invitar a salir   o algo?
SCOUT                            No, Y-yo... bueno, no, no iba    a... Mira, tan sólo no me        gustaría perderte.
SCOUT                            No estamos enfadados contigo,    y... oye, tampoco me gustaría    echar a perder nuestra amistad
SCOUT                            sólo porque estés enfadada, ¿ok? Eres más importante que la isla. Y yo...
SCOUT                            Quiero que me prometas que no    irás a ningún lado ni harás nada estúpido por lo que ha ocurrido.
MAPLE                            ...
MAPLE                            ... No lo haré, Scout. No tienes que preocuparte tanto por mí.

...

ENOKI                            ¡Hey, Maple! ¿Ya estás de vuelta?
MAPLE                            Sip. La entrevista ha ido bien.  Estar en el ejército parece un   rollo pero los beneficios        son cuantiosos.
AARON                            Sé que te irá genial, Maple.
MAPLE                            ¿Eso piensas?
AARON                            Apuesto a que serás la única     elfa del pelotón. Y eso jugará a tu favor.
MAPLE                            Sí, eso creo. He hablado con     Scout sobre esto. Dice que está  feliz pero que me echará         de menos.
ENOKI                            Nosotros también te extrañaremos.
ENOKI                            Bueno, Aaron y yo también        tenemos una noticia que darte.
MAPLE                            Vaya, ¿qué noticia?
ENOKI                            Parece que pronto... Uh...       Que pronto habrá un nuevo        Tremblay junto a nosotros.
MAPLE                            Espera, ¿No me digas que-?
ENOKI                            ¡Ahá!
MAPLE                            Estás... ¿EMBARAZADA?
AARON                            Así es, señorita.
MAPLE                            No puede ser, Voy...             Voy a ser tía. ¿Qué clase de     persona saldrá de una mezcla como Aaron y Enoki?
ENOKI                            el 2000 ha sido un año increíble,¡y estoy segura de que el 2001   será aún mejor!
AARON                            Sea cual sea la aventura que nos aguarde, me alegro de que estéis a mi lado para vivirla.
MAPLE                            ¡Feliz 2001, chicos!
ENOKI                            ¡Happy 2001!
SCOUT                            Maple, comment ça va?
MAPLE                            ...
MAPLE                            ... N'ose pas t'inquiéter pour moi. C'est clair?
SCOUT                            Oui, bien sûr, c'est juste... je suis désolé pour-
MAPLE                            Que ressentes tu tant?
SCOUT                            Laissez-moi finir.
MAPLE                            Bon. Continue.
SCOUT                            Désolé d'être audacieux, mais s'il te plaît, arrête de te blâmer autant. Je suis de ton côté, tu connais?
MAPLE                            Quoi, tu vas m'inviter à sortir ou quoi?
SCOUT                            Non, je-je... eh well, non, je n'y suis pas... Écoute, je ne voudrais juste pas te perdre.
SCOUT                            Nous ne sommes pas en colère contre toi, et... hé, je ne voudrais pas gâcher notre amitié non plus.
SCOUT                            juste parce que tu es en colère, d'accord? Tu es plus important que l'île. Et moi...
SCOUT                            Je veux que tu me promettes que tu n'iras nulle part ou que tu ne feras rien de stupide à cause de ce qui s'est passé.
MAPLE                            ...
MAPLE                            ...Je ne le ferai pas, Scout. Tu n'as pas à t'inquiéter autant pour moi.

...

ENOKI                            Hé, Maple! Tu es de retour?
MAPLE                            Oui. L'entretien s'est bien passé. Être dans l'armée ressemble à une corvée, mais les avantages sont énormes.
AARON                            Je sais que tu t'en sortiras très bien, Maple.
MAPLE                            Le penses toi?
AARON                            Je parie que tu seras le seul elfe du peloton. Et cela jouera en votre faveur.
MAPLE                            Oui, je pense que oui. J'en ai parlé à Scout. Il dit qu'il est heureux mais je vais lui manquer.
ENOKI                            Tu nous-autres manqueras aussi.
ENOKI                            Well, Aaron et moi avons aussi des nouvelles pour toi.
MAPLE                            Wow, quelles nouvelles?
ENOKI                            Il parait que bientôt... Euh... Que bientôt il y aura un nouveau Tremblay avec nous.
MAPLE                            Attendez, ne me dites pas quoi-?
ENOKI                            Ah!
MAPLE                            Êtes tu... ENCEINTE?
AARON                            C'est vrai, mademoiselle.
MAPLE                            C'est pas possible, je suis... je vais être tante. Quel genre de personne sortira d'un mélange comme Aaron et Enoki?
ENOKI                            2000 a été une année incroyable, et je suis sûr que 2001 sera encore meilleure!
AARON                            Quelle que soit l'aventure qui nous-autres attend, je suis content que tu sois avec moi.
MAPLE                            Bonne année 2001, les gars!
ENOKI                            Bonne année 2001!

Credits:

                        MAPLE TREMBLAY
                        Natalie Anderson
                        - - - - 
                        MARIA 'ENOKI' TREMBLAY
                        Brianna Beamer / Mely-Anne Dupuis
                        - - - - 
                        AARON TREMBLAY
                        Josh Hollwarth
                        - - - - 
                        RUFUS THIBODEAUX
                        Patrick Williams
                        - - - - 
                        built with Butano
                        github.com/GValiente/butano
                        - - - - 
                        Scout desktop sketch by
                        @yae.ruu (Instagram)
                        - - - - 
                        based on characters
                        from 'Vous Voila' by
                        Ethan Hill
                        created by
                        Ethan Hill
                        - - - - 
                        - - - - 
                        SPECIAL THANKS:
                        - - - - 
                        my friends and family
                        r/cajunfrench
                        LETU Game Design Club
                        Thank you for playing!
                        Merci d'avoir joue!
                        - LA FIN - 
                        - - - - 

Créditos:
Crédits:

                        MAPLE TREMBLAY
                        Natalie Anderson
                        - - - - 
                        MARIA 'ENOKI' TREMBLAY
                        Brianna Beamer / Mely-Anne Dupuis
                        - - - - 
                        AARON TREMBLAY
                        Josh Hollwarth
                        - - - - 
                        RUFUS THIBODEAUX
                        Patrick Williams
                        - - - - 
                        Creado con Butano
                        github.com/GValiente/butano
                        - - - - 
                        Fondo de escritorio de Scout: 
                        @yae.ruu (Instagram)
                        - - - - 
                        Basado en los personajes 
                        De 'Vous Voila' por
                        Ethan Hill
                        Creado por
                        Ethan Hill
                        - - - - 
                        - - - - 
                        AGRADECIMIENTOS ESPECIALES:
                        - - - - 
                        A mis amigos y familia
                        r/cajunfrench
                        LETU Game Design Club
                        ¡Gracias por jugar!
                        Merci d'avoir joue!
                        - LA FIN - 
                        - - - - 
"""

locs = [t * 33 for t in range(12)]

replace = {
    "á":"a",
    "é":"e",
    "í":"i",
    "ó":"o",
    "ú":"u",
    "ü":"u",
    "ñ":"[",
    "¿":"{",
    "¡":"}",
    "Á":"A",
    "É":"E",
    "Í":"I",
    "Ó":"O",
    "Ú":"U",
    "Ü":"U",
    "Ñ":" ",
    "â":"a",
    "ê":"e",
    "î":"i",
    "ô":"o",
    "û":"u",
    "à":"a",
    "è":"e",
    "ì":"i",
    "ò":"o",
    "ù":"u",
    "ë":"e",
    "ï":"i",
    "ü":"u",
    "â":"a",
    "ê":"e",
    "î":"i",
    "ô":"o",
    "û":"u",
    "à":"a",
    "è":"e",
    "ì":"i",
    "ò":"o",
    "ù":"u",
    "ë":"e",
    "ï":"i",
    "ü":"u",
    "ŕ":"r"
}

# â/ê/î/ô/û/à/è/ì/ò/ù/ë/ï/ü

output = []
for line in data.split('\n'):
    n = line
    o_offset = 0

    for key in replace.keys():
        n = n.replace(key, replace[key])

    for l in locs:
        pos = l
        offset = 0
        if (pos < len(n) and len(n) > 3):
            while(n[pos] != " " and pos >= 0):
                pos -= 1
                offset += 1
            o_offset = offset
            while(offset > 0):
                n = n[:pos] + " " + n[pos:]
                offset -= 1
            n = n[:l] + n[l] + n[l:].lstrip()
    output.append(n)

with open("honyaku.txt", "w") as f:
    for o in output:
        f.write(o[1:] + "\n")