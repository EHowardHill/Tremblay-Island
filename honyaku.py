import os, pprint

data = """
4:15 AM                          January 1st, 2000                Providence of Nord Louisiane,    La Republique Laurentides
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

04h15 					1er Janvier 2000 Province Nord de Louisiane, Republique des Laurentides
                                 AHHHHH. J'ai conduit pendant des heures. Mon pied droit a des fourmis et l'autre va le rejoindre.
                                 Et c'gombo... Il vas etre frette maintenant. J'arrive pas a croire qu'ils voulaient que je leur apporte de la nourriture.
                                 Pour etre franche... Si j'vois pas ce chateau dans quinze minutes, j'vais peut-etre faire demi-tour.
                                 Le trajet etait agreable, je suppose.
                                 Bon, j'abandonne. Il y'a pas moyen-
                                 .....Oh.
                                 J'peux pas dire si j'suis soulagee ou decue.

                                 *Toc Toc Toc*
                                 J'me demande s'ils peuvent m'entendre... Cet endroit semble immense.
                                 '... ey!'


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
MAPLE                            So, how long are you two going tostay here? You can't just stay   thirty miles from civilization   without electricity forever.
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

ENOKI                            He, Maple! C'mon in, allez!
MAPLE                            D'accord, ou J'branche cette mijoteuse? Y a-t-il des prises icitte?
MAPLE                            J'suppose que j'suis en retard et que t'as deja mangee?
ENOKI                            On a un evier exterieur, mais c'est la seule place avec de l'electricite. Et oui, on a mange du poulet.
ENOKI                            Tu nous as vraiment manque!
MAPLE                            Eh bien, j'suis enfin arrivee. Ou est- Oh! Salut, Aaron.
AARON                            Bonsoir! Ou plutot Bonjour, on est deja demain. Non? Quoi qu'il en soit, nous sommes heureux de te voir. Joyeux millenaire!
MAPLE                            Joyeux millenaire! Vous etes au milieu de nulle part, vous le savez, non?
DEL                              Maple! Tu es la! Joyeux 2000!
MAPLE                            Delphine Thibodeaux! Salut! Mon Dieu, ca fait combien de temps deja? Un an? 
DEL                              He fille! Quelle joie de te voir. On t'a attendue pour ouvrir le vin et sortir les eclairs.
DEL                              Bien qu'on n'est tous des adultes ennuyeux maintenant. Donc j'peux pas te promettre qu'on va veiller tard.
ENOKI                            He Maple, comment ca va?  On s'est pas vraiment parlees depuis le mariage?! Ma meilleure amie m'a manquee!
MAPLE                            Ton mari a du t'occuper, j'suppose.
AARON                            Well, comme tu vois, nous vivons dans un chateau desormais, et c'etait toute une aventure.
ENOKI                            Je suis une princesse.
MAPLE                            Il te faudrait plus qu'un chateau pour etre une princesse.
ENOKI                            Alors je suis une duchesse?
MAPLE                            Je- euh... Hmm... You know what? Il est trop tard pour ca.
MAPLE                            Ca va bien pour moi, j'ai besoin d'un dernier semestre pour etre enseignante. Apres? J'sais pas.
AARON                            Tu es encore sur ca, tu veux etre prof, hein? Meme si tu as toujours dit que tu serais tout sauf une prof?
AARON                            Y'a pas des diplomes pour les gens qui crache du feu avec leurs mains?
MAPLE                            Pas un qui m'interesse, du moins.
AARON                            Well, une prof avec de la magie de feu me semble cool.
ENOKI                            *Aaawn* my goodness, je m'endors. Et si on allait se coucher et finir de parler demain?
ENOKI                            Hey Maple, on fais tu une soiree pyjama? On pourrait faire comme si on etait encore colocs d'universite?
MAPLE                            Euh... Ok, je suppose.
ENOKI                            Bonne nuit Del! Eh Aaron, Je te vois demain matin? Ben tot?
AARON                            Bien sur, Noc-Noc. *Bisou*
MAPLE                            Je m'y habituerai jamais.
ENOKI                            Tres bien, attrape ta valise et je te montre ou on dort. Allons-y!
MAPLE                            Wow... Il fait froid ici, non?
ENOKI                            He silly, qui porte un debardeur et un short en plein decembre? Tu peux juste allumer un feu.
MAPLE                            Alors, pendant combien de temps vous restez ici? Tu peux pas etre a 50 km de la civilisation sans electricite pour toujours.
ENOKI                            On est heureux ici, donc j'pense qu'on va rester ici longtemps.
MAPLE                            Et Aaron y pense quoi? L'Aaron que je connaissais aurait ete un peu plus... responsable.
ENOKI                            Je veux pas paraitre mechante mais... Vous n'avez pas grandi dans un char vous deux?
MAPLE                            Enoki, On sait tous que t'es riche, t'a pas besoin de te vanter.
ENOKI                            Mais t'as vraiment grandie dans un char? Comparez a ca, un chateau, c'est mieux, non?
MAPLE                            C'est juste... C'est fou. Je me moque pas de toi ou quoi que ce soit du genre, mais j'pense reellement que c'est une tres mauvaise idee.
ENOKI                            Et ca vient de la fille qui avait honte de ses notes en premiere annee et a decidee d'abandonner l'universite...
MAPLE                            Come on, c'etait ton idee en plus.
ENOKI                            He, j'assume!! '97... Ouais, c'etait vraiment l'une des meilleures annees de ma vie.
ENOKI                            Donc, apres l'ecole, tu as un plan pour ou vivre?
MAPLE                            J'vais trouver quelque chose.
ENOKI                            Aaron et moi discutions et, tu sais, il y a une ecole pas trop loin ou tu pourrais enseigner, tu pourrais... vivre avec n...
MAPLE                            Oh que NON. J'vais me trouver un vrai appartement d'adulte.
MAPLE                            Quand tu seras tanner d'icitte, tu pourras peut-etre vivre avec moi.
ENOKI                            Ton sens de l'humour Maple, Il arretera jamais de m'etonner.
ENOKI                            Hey- Je suis triste et c'est stupide! Tu veux faire une aventure Maple et Enoki comme au bon vieux temps?!
ENOKI                            Explorons le chateau!!
MAPLE                            Attends, tu as achetee ce chateau et tu ne l'as pas toute visitee?
ENOKI                            Duh, je prends mon temps avec ca - c'est un chateau! Allons-y!

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
ENOKI                            So, we found this island up in   Lake Superieur called Tremblay  Island!
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

ENOKI                            Je veux visiter la bibliotheque en premier!
MAPLE                            Bien sur, en avant.
ENOKI                            Tu vas comprendre pourquoi quand on y seras!
ENOKI                            Si veux que j'mene, appuis sur 'B'.
MAPLE                            ...Uh,?
ENOKI                            Quoi?
...
AARON                            Bonjour! As tu bien dormi?
MAPLE                            Oui, je crois.
ENOKI                            Bonjour! Hey... On as trouve quelque chose de cool pendant que tu dormais, mais tu dois me promettre que tu ne vas pas te facher!
MAPLE                            Tu sais que je peux pas te le promettre.
ENOKI                            Tu te souviens du livre que tu voulais que je prenne? Well, c'est un Atlas et nous avons vu quelque chose de fun!
ENOKI                            Nous avons trouve une ile du lac Superieur appelee Tremblay Island!
MAPLE                            Aww, c'est marrant. Je pensais que tu allais dire un jeu de mots ou quelque chose comme ca.
ENOKI                            Well, nous, euh- nous pensions que ce serait amusant si, eh bien, Del avait l'idee, d...
DEL                              La derniere fois que j'ai vus mon cousin Rufus, il etait obsede par la creation d'un petit pays.
AARON                            Il y a du travail proche, donc ca devrait pas etre difficile d'obtenir les fournitures qu'on a besoin.
ENOKI                            Avec l'argent que nous recevrons en vendant le chateau et grace a ta magie, on pensait que-
MAPLE                            WHOA WHOA WHOA, ATTENDEZ UNE MINUTE.
MAPLE                            Etes-tu vraiment en train de dire que vous allez VENDRE le chateau pour vivre sur cette ile-
MAPLE                            parce que nous avons le meme nom de famille que celle-ci?
ENOKI                            En plus, on voudrais  nous detacher des Laurentides pour fonder notre propre pays.
MAPLE                           ... je...
MAPLE                           ...
MAPLE                           ... Je pense que je vais avoir besoin de temps pour assimiler tout ca.
AARON                            Ca peut sembler fou, mais nous avons fait des recherches et ca serais quelque chose de possible.
ENOKI                            Je sais qu'on a eu une conversation hier, mais...
MAPLE                            Et apres? Que vas-tu faire lorsque tu... tu vas etre tanner d'avoir unev ile?
MAPLE                            Tu vas devenir Pape? Peut-etre la reine de France? Tu vas acheter ta propre planete?
MAPLE                            Et tu as tellement de chance que tu vas l'avoir. Mais, but you know what?
MAPLE                            Je vais garder les pieds sur terre avec un *vrai* travail et eviter de mourir de faim sur une roche.
MAPLE                            Ou pire encore, me faire enfermer pour avoir brise une loi stupide.
MAPLE                            Bien ... J'ai aime mon sejour, mais je vais allez chez moi. Je suis tannee.
MAPLE                            Aaron, Enoki, Delphine, je suis contente de vous revoir, mais j'ai besoin de prendre du temps.
AARON                            Tu es sur? On peut parler d'autre chose. Tu peux aussi prendre le petit dejeuner avec nous-autres si tu veux.
MAPLE                            ...Well, je vais rester un moment, mais je dois partir bientot.

                                 Hmm, hmm, hmm....
                                 Mon Dieu, ma pizza est vraiment en retard, elle devait etre icitte en moins de 20 minutes.
                                 J'ai tu checker la malle aujourd'hui? Je devrais le faire en passant.
                                 Hein, Ca viens? De la maison Tremblay? J'ai pas eu de nouvelles d'Aaron et d'Enoki depuis un moment.
                                 J'ai hate de lire a quel point ils veulent venir vivre avec moi.

He, Maple!
                                 Oh, elle est a l'envers.

                                 'He, Maple!'
                                 "Nous avons pense a t'envoyer une lettre pour te tenir informee"
                                 "Nous avons vendu le chateau et achete un trailer.
                                 "C'est pas tout, on l'a deja installe sur notre nouvelle ile!"
                                  ...  Ok. Je vais les tuer.
                                 'Alors nous avons decide de l'appeler-..'

MAPLE                            Oh my gosh, j'en ai ASSEZ, ils vont voir!
MAPLE                            Je suis a ma limite, ils vont MOURIR SEUL. Et ca va etre leur faute.
MAPLE                            Quand ils vont etre tannes de leur ile, ils vont venir ici, et tu sais ce que je vais leur dire?
PIZZA GUY                        Que vas-tu dire?
MAPLE                            Je vais dire NON!
PIZZA GUY                        A mon avis, vivre sur une ile, tout seul, semble parfait.
MAPLE                            Oui, c'est une vie de reve, mais ils vont la gacher, parce qu'ils sont tous completement incompetents!
PIZZA GUY                        Si j'etais toi, j'irais les rejoindre et je leur montrerais comment gerer l'ile.
MAPLE                            Je vais devoir y aller hein? Ils vont mourir la-bas. 
MAPLE                            Mais je peux pas. Je dois etre une meilleure personne et rester dans le vrai monde.
PIZZA GUY                        Ouais, c'est plus important de continuer a manger de la pizza et de pleurer pour t'endormir comme a chaque soir non?
MAPLE                            Ca se voit?
PIZZA GUY                        Oui, on prend tous notre tour pour livrer la pizza a 'la fille seule deprimee'.
MAPLE                            Incroyable.
MAPLE                            Eh bien, c'est vrai qu'apres avoir commandee autant de pizza, j'ai plus de piastre pour mon loyer.
PIZZA GUY                        Well... j'ai toujours mon pourboire pour la session de therapie?

6:40 PM                          March 20th, 2000                 The middle of Lake Superieur,   La Republique Laurentides(?)
                                 So.. That's the island.          It's cute.
                                 I'm not sure if it's sell-every- thing-I-own cute, but...
                                 J'suppose the thought of living  on an island and having no debt  is pretty cool.        
MAPLE                            How much was the ferry again?    10 dollars?
OLD SAILOR                       Aye lass, but aye've got one     warnin' fer ye befer ye dock.
MAPLE                            Oh dear, what?
OLD SAILOR                       Keep yer wits about 'ye, ye neverknow who might go to stab ye.
MAPLE                            Will you take a 20?
OLD SAILOR                       Aye, I can cut a 20.

18h40                            20 mars 2000 Au milieu du Lac Superieur, La Republique Laurentides(?)
                                 Alors... C'est l'ile... Elle a du charme.
                                 Ont verras si elle a assez de charme pour que je reste.
                                 J'suppose que l'idee d'vivre sur une ile sans avoir de dettes est interessante.
MAPLE                            Combien ca cout le trajet en traversier? 10 dollars?
LE VIEUX MARIN                   Oui fille, mais j'dois te dire quelque chose avant que tu parte.
MAPLE                            Hold up, quesqu'il a?
VIEUX MARIN                      'Fais attention la-bas, on sait jamais qui peux te poignarder dans l'dos.
MAPLE                            Vous pouvez couper un 20?
VIEUX MARIN                      J'peux oui.

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
   
ENOKI                            Maple, tu es venue!
MAPLE                            Well oui, jsuppose c'etait ma meilleure option.
AARON                            Comment s'est passe le voyage? Ca as tu pris longtemps?
MAPLE                            J'ai prit un train. Ca m'a pris environ... Trois jours? C'etais pas mal, j'ai beaucoup lis et j'ai mal aux jambes.
AARON                            Si tu nous avais dit que tu venais, nous aurions paye un avion!
MAPLE                            Pas grave Je suis la. Alors, tu es passe d'un chateau a un camper? La classe.
ENOKI                            Dude, on as demenage d'un chateau a une maison 'normale' et maintenant tu veux qu'on y retourne ou quoi?
MAPLE                            Non, je dis juste que... en faite je sais pas.
AARON                            Well, on n'a qu'un sofa, mais il est super comfo, donc fais comme chez toi.
AARON                            Nous avons travaille a la sueur de nos front. J'ai coupe beaucoup de bois de pour l'hiver, et Enoki-
ENOKI                            Je croyais qu'emmener quelques lapins allais rendre l'ile plus vivante, y'know?
ENOKI                            Eh bien, ils se sont multiplier et je dois les tenirs hors du jardin.
AARON                            Que pense-tu de visiter les grottes au Nord?
AARON                            J'ai entendu dire qu'elles contiennent des gemmes qui serais utile pour obtenir de l'argent.
MAPLE                            Ca semble pas difficile.
MAPLE                            Et... merci pour la chambre.
AARON                            De rien.
ENOKI                            Oh, et si t'a pas vus Scout, c'est un gars cool! Il est surement dans son bunker a l'exterieur.

ENOKI                            Well... Premiere journee terminee! C'etais amusant.
MAPLE                            Tu sais quoi? Je suis d'accord. C'est la journee la plus interessante que j'ai eue depuis longtemps.
AARON                            Es tu prete a avoue que c'etais pas une mauvaise idee?
MAPLE                            Je suis ici que depuis une journee, j'ai besoin d'un moment avant mon jugement final.
AARON                            C'est dommage que nous n'ayons qu'un sofa. Mais nous sommes heureux que tu restes avec nous-autres jusqu'a ce que la maison soit finie
MAPLE                            Je dormais sur mon propre sofa dans mon appartement, t'en fais pas.
ENOKI                            Aw, tu dormais sur ton sofa?
MAPLE                            Il etait comfo mon sofa.
AARON                            Dans tous les cas, on devrait se reposer. J'ai coupe du bois toute la journee et je suis fatigue.
AARON                            A demain?
ENOKI                            Je suis sur que je vais trouver plus de chose a faire!
MAPLE                            Merci beaucoup.. Je vais essayer de pas trop etre chiante tout le temps. Bonne nuit!
ENOKI                            Bonne nuit!

                                 Ugh... Ma tete... J'arrive pas a dormir.
                                 Je croyais qu'apres un trajet et une longue journee de dur labeur, on devait dormir facilement?
                                 Et c'est quoi la lumiere a l'exterieur? C'est peut-etre Scout...
                                 Je devrais surement sortir et jeter un coup d'oeil.
                                 quoi-? C'es tu un Mons de Plonj? Ecris t'il quelque chose?
                                 Je devrais aller voir avant que quelque chose de grave n'arrive.
                                 Hmm, hmm... hmm...
                                 HE! IDENTIFIEZ-VOUS OU JE FAIS UN BARBECUE AVEC VOTRE VISAGE!
                                 AHHH?!
                                 OH, HUH... HUH, RUFUS! RUFUS THIBODEAUX!
                                 J'AI BESOIN DE MON VISAGE, S'IL VOUS PLAIT NE LE BRULE PAS!    

MAPLE                            Oh, alors vous etes le fameux Rufus? Le cousin de Del? Je suis Maple.
RUFUS                            Oh, vous etes l'elfe du feu? J'aurais aime le savoir avant d'essayer d'allumer ce feu.
MAPLE                            Que faite-vous ici?
RUFUS                            Je fais de la reconnaissance. J'ai un oeil sur les iles Bill & Jim a cote.
RUFUS                            J'aime l'idee d'avoir un endroit rien que pour moi, sans avoir affaire a personne.
RUFUS                            Je suis juste preoccupe par la temerite de mon 'ile privee'.
RUFUS                            En plus, tous ceux qui habitent pres de Quebec parlent avec cet accent enervant...
MAPLE                            Ca m'inquiete aussi. Enoki est super, mais parfois cet accent me tape sur les nerfs.
MAPLE                            Je commence a entendre l'accent quebecois se glisser dans la voix d'Aaron. Vraiment enervant.
MAPLE                            Donc, qu'est-ce que vous ecrivez?
RUFUS                            ... Vous allez penser que c'est idiot, mais je fais un dessin.
MAPLE                            Eh, apres avoir vendu toutes mes affaires pour venir sur cette ile, je t'assure que votre dessin n'est pas idiot.
RUFUS                            ... Okay, c'est une grenouille. J'ai vu une photo quand j'etais petit et ca me rend nostalgique pour une raison quelconque.
RUFUS                            Je ne me souviens pas reellement de l'apparence, alors je continue d'essayer. Je sais pas pourquoi, mais je sens que je dois le faire.
MAPLE                            Ouais, quand vous l'expliquez, ca a l'air un peu idiot, mais je comprends!
MAPLE                            Au fait... Avez-vous un endroit ou dormir? Je ne peux pas offrir grand-chose, mais il fait froid dehors et nous avons un bain.
RUFUS                            J'apprecie, mais je pars demain matin. Et j'ai assurement pas envie de parler a qui que ce soit, meme si vous semblez bien.
MAPLE                            Ce fut un plaisir de parler avec quelqu'un avec du sens.

MAPLE                            Prends bien soin de toi, d'accord? Ravi de vous rencontrer, Rufus.
RUFUS                            Toi aussi! Ravi de vous rencontrer, Maple.

                                 Bonjour Scout est de retour! 

                                 C'est excitant d'avoir enfin un vrai public, mesdames et messieurs. Euh... monsieur.
                                 Aujourd'hui, c'est le 1er avril, et vous savez ce que ca veux dire!
                                 Maple a demenagee sur l'ile depuis hier! Comme le temps passe!
                                 C'est une, euh, blague... Parce qu'on est le 1er avril, et elle est avec nous-autres depuis un mois entier.
                                 Je-je vais passer a autre chose... Bien! J'ai enfin pu recuperer le mot de passe de mon PC...!
                                 Oh, d'accord, d'accord, quelque chose de plus important. Trois nouvelles personnes s'installent sur l'ile!
                                 Mais je suis pas sur qu'on va trouver plus d'insulaires potentiels sur Craigslist.
                                 Ils s'appellent Diana, Eleanor et Olivier. Et ils emmenagent dans la nouvelle cabine au nord-ouest.
                                 Olivier a une serre dans le nord et Diana est une navigatrice aspirante. Elle s'occupera de conduire le navire.
                                 Alors accueillons-les chaleureusement!

                                 D'accord, c'est tout... Je suppose que je vais tous vous voir plus tard. Merci beaucoup d'etre la!

ENOKI                            Mmmmmm.... J'ai fait du pop-corn, mais j'ai pas envie d'aller le chercher.
ENOKI                            Peux-tu aller le chercher, Maple? S'il te plait?
MAPLE                            Ugh, prenez-vous une chambre vous deux!
AARON                            Mais, c'est notre maison.
MAPLE                            Alors?

SCOUT'S COMPUTER LOGS:

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
                                 but maybe she's just playing hardto get.
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

1er avril 2000 - Carnet d'exploration, n? 48
                                 Scout TV a eu quelques telespectateurs cette fois. J'espere qu'ils ont aime.
                                 La prochaine fois, j'aimerais en avoir assez pour creer l'Expo Scout.
                                 Les choses avancent lentement mais j'ai du financements donc.
                                 Je peux au moins travailler sur des projets personnel 
                                 La 'Magic Pocket' ne sera pas pret avant un moment, mais le
                                 prototype est prometteur.
                                 Ca pourrait etre utile pour la demande d'Aaron?
                                 Il voulait faire des courses de voitures sur l'ile.
                                 Je pourrais mettre une piste de course entiere dans la dimension magique de la pocket.
                                 De cette facon, on pouras laisser l'ile propre.
                                 Bien sur, tout doit etre parfait Je veux pas qu'il reste prit...
                                 ...eh, it'll be fine.

1 mai 2000 - Carnet d'exploration n? 68
                                 Deux nouveaux villageois sont arrives, l'un est un peu louche mais Enoki lui fait confiance.
                                 L'autre gars est un grand chef, en plus son nom de famille est Pizza.
                                 Je connais pas son vrai prenom et la curiosite me tue.
                                 Rufus a ete enervant et il a interrompue Scout TV.
                                 Il a un probleme d'ego ou quoi?
                                 Je suis un peu inquiet. Je devrais peut-etre le garder sous surveillance.
                                 Je veux dire, encore plus qu'avant.
                                 Il semble qu'une entreprise veuille stocker beaucoup d'gasoline sur l'ile.
                                 J'ai decouvert ca quand ils en on amenee par accident.
                                 Il vas faire quoi avec toute cette gasoline? Peut-etre que l'avenir nous le dira.
                                 J'espeere que le monde va bien ce mois-ci. Je m'amuse beaucoup avec eux.
                                 Scout out. Hehe, 'scout out'.

29 mars 2000 - Carnet d'exploration n?45 (supprime)
                                 Depuis mon depars des iles Bill & Jim, c'est l'une de mes meilleurs journees.
                                 Ces iles ne me manquent definitivement pas.
                                 Rufus etais comme un coup de pied dans les couilles. Toujours en train de chialer
                                 avec toutes ses idees de complot.
                                 J'espere qu'il se porte bien tout seul.
                                 Mais, cette fille Maple... Ouf. Je crois qu'elle m'a souri pour la premiere fois
                                 Depuis son arrivee sur l'ile.
                                 Ca veut probablement rien dire, mais chaque fois que j'y pense,
                                 Je dors pas.
                                 Elle ne m'a jamais parle autre que quand elle se moque de moi...
                                 Mais peut-etre qu'elle joue la difficile.
                                 J'ai vu comment elle parle avec Aaron et Enoki, elle semble pareille avec tout le monde.
                                 Hmm... Peut-etre qu'un jour, je trouverai comment l'approcher.
                                 Je ferai quelque chose pour l'impressionner.
                                 Elle n'aime pas grand-chose, mais elle semble aimer les livres et manger.
                                 C'est peut-etre pas les memes, mais j'aime aussi les livres et la nourriture.
                                 Surement qu'elle aime les gars muscles et je ressemble plus a Grimace de McDonald's.
                                 He, je pourrais inventer quelque chose pour me mettre en forme.
                                 Apres tout, elle m'a souri. Meme si c'est parce que j'ai tombe
                                 sur quelque chose...
                                 Je vais supprimer cet enregistrement. Je sais meme pas pourquoi je l'ai ecrit.
Dialogue before the boat minigame

CAP'N NICHOLAS                   Ahoy there, lass! Are ye ready   fer yer a voyage?
DIANA                            Aye aye, Captain!
CAP'N NICHOLAS                   Just remember what I told ye' -  watch out fer the rocks, and     watch yer speed!
DIANA                            Aye aye, sir!

CAP'N NICHOLAS                   He, fille! Pret pour le voyage?
DIANA                            Oui, capitaine!
CAP'N NICHOLAS                   Rappelle-toi ce que j'ai dit -  Evite les rochers et fait attention a la vitesse!
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
    (I know it's probably too soon tocall, but Aaron Tremblay-
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
(There's no way I'm going to everadmit it, but...)
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
(Y'know, this room hasn't changedin a bit.)
(What if I moved the bed to the  other side of the room?)
(Hmm, then it'd be harder to hideclothes from guests.)
(I gotta pick those up.. eh...   later, later is good.)

AARON
(Well, there goes the last chancefor Maple to take the cabin.)
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

MAPLE                            Enoki, y'a pas de fenetre.
ENOKI                            Euh?
MAPLE                            Et si quelqu'un
MAPLE                            tente de vous voler?
ENOKI                            Aaron le frappera.
ENOKI                            Dans la face.
MAPLE                            Mais il n'est pas avec nous.
ENOKI                            Alors je vais le frapper.
MAPLE                            Euh... Hum. C'est bien, je suppose.

Vous voyez un vase.
Tu sens que tu devrais le briser.
Mais tu n'y arrives pas.
Une etrange deception t'envahit.

MAPLE                            Nous ferions mieux d'y aller.
ENOKI                            C'est bon. Il dort avec la lumiere allumee.
MAPLE                            Je pensais que ta prise electrique etait a l'exterieur?
ENOKI                            Well, on a une autre, c'est la seule, elle est tres importante.
MAPLE                            Aimes-tu vraiment ca ici?
ENOKI                            Es-tu venu juste pour te plaindre de ma maison?
MAPLE                            Non, pas du tout...
ENOKI                            Donc, je disais.
MAPLE                            Je m'excuse.
ENOKI                            Merci.
MAPLE                            Mais quand vous allez venir vivre chez moi,
MAPLE                            Dit pas que je t'avais pas prevenue.

ENOKI                            Savais-tu, quand Del etait ma gardienne, mes parents lui ont offert trois chambres pour dormir. Mais Del dormait toujours dans le bain
MAPLE                            Well, ca ne sonne pas si mal.
ENOKI                            Ouais, j'ai essaye, mais ma peau n'a pas trop aime.

MAPLE                            Enoki, c'est verrouille.
ENOKI                            Oh. Oui, je pense que c'est la cuisine. Mais on ne sait pas ou est la clef.
MAPLE                            Comment vous faites a manger d'abord'?
ENOKI                            Nous cuisinons presque tout sur le feu de bois!
MAPLE                            Vous deux, je jure!

ENOKI                            N'est-il pas trop mignon quand il dort? <3
MAPLE                            Cela fait pas plusieurs mois que vous etes maries?
MAPLE                            C'est pas deja l'heure de la phase dans laquelle vous ne vous parlez pas quand vous mangez et que vous avez pris 10 livres?
ENOKI                            Euh, je pense que j'ai meme perdu du poids.
MAPLE                            Je comprendrais jamais.
ENOKI                            C'est pas parce que tu es toujours en combat avec tes ex que tous les couples sont comme ca.
ENOKI                            En plus tu toujours la mauvaise habitude de-
MAPLE                            Si tu finit cette phrase,
MAPLE                            Je vais te bruler les cils.
ENOKI                            ...Mon point est fait.

ENOKI                            Nous sommes ici!
ENOKI                            Voici la bibliotheque!
MAPLE                            Je vois que tu ne plaisantais en disant que c'etais juste une bibliotheque...
ENOKI                            Bon, nous autres on a pas pu la bouger. Pourrais-tu me rendre service et utiliser ta magie elfique?
MAPLE                            Ok si je comprends...
MAPLE                            Tu veux que je *brule* une bibliotheque presque neuve?
ENOKI                            Je veux verifier s'il y a un passage secret derriere elle ou quelque chose, tu sais?
MAPLE                            Je refuse. C'est stupide.
MAPLE                            En plus, ces livres ont l'air bien.
ENOKI                            La plupart son en train de moisir.
ENOKI                            Je les ai deja verifies. Les bruler serais la meilleur solutions.
MAPLE                            en es-tu sur?
ENOKI                            Completement.
MAPLE                            OK, faisons un marche alors.
MAPLE                            Je vais bruler tous bruler, mais tu dois garder un livre.
MAPLE                            Compris?
ENOKI                            Oui! ... Ok, j'ai pris un livre.
ENOKI                            Utilise le bouton 'R' pour lancer une boule de feu!
MAPLE                            ...De quoi?
ENOKI                            Hein? Oh, it's nothing.

MAPLE                            ....
ENOKI                            Eh bien, il n'y a pas de passage.
MAPLE                            Wow, vraiment.
ENOKI                            Comme c'est etrange.
MAPLE                            Enoki...
MAPLE                            Je suppose que ca sert a rien de se facher contre toi, mais tu devrais arreter d'agir comme ca.
MAPLE                            Toi et Aaron avez depense une fortune dans un chateau non meuble.
MAPLE                            Et pourquoi? Pour jouer a la princesse? Pendant ce temps, je sacrifie ma jeunesse dan un apartemnt en Caroline avec juste le necessaire.   
MAPlE                            Enoki... Je t'en pris.
MAPLE                            Je veux pas etre le mechant dans cette histoire.
MAPLE                            Je sai que tu n'aies pas eu une bonne enfance etant si loin de tes parents...
MAPLE                            Mais tu peux pas continuer a agir comme ca. You get it?
ENOKI                            Je comprends.
MAPLE                            Il est 5 heures du matin, je retourne me coucher. Je te verrai demain matin, oui?
ENOKI                            Oui...
MAPLE                            Ne pense pas trop a ce que j'ai dit. S'il te plait, bonne nuit.
ENOKI                            Bonne nuit...

MAPLE
     (Chacun de ces vetements sont vraiment a Enoki?)
     (Bien sur, Aaron a les siens.)
     (Ils sont si differents... Je comprends pas comment il ne dispute pas tous le temps. Je comprends pas.)
     (Si j'avais un mari, je le forcerais a ramasser tous ses vetements immediatement.)

ENOKI
     (Si j'avais su que Maple arrivait si tot, j'aurais nettoyer plus vite...)
     (Peut-etre qu'elle va pas remarquer si je commence a ramasser maintenant)
     (Mais peut etre qu'elle a deja remarquer et qu'elle ma juge deja)
     (... Celui-ci est mignon, peut-etre que je le porterai demain.)

AARON
     (Enoki n'etait pas aussi malprorpe quand on vivais dans le chateau.)
     (Elle doit penser que nous somme installee et  elle commence a se sentir a l'aise.)
     (Bien que ce soit trop tot pour le dire, Aaron Tremblay,
     Tu as reussi. Tu as une maison a toi et une femme
     qui laisse trainer ses vetements par terre.)
     (Je ne peux penser a rien d'autre que je voudrais avoir en ce moment.)
     (Well... ma voiture me manque.)
     (Je devrais parler a Scout pour la mise en place d'une piste de course.)

LES AUTRES
    (Je devrais pas etre ici.)

MAPLE
(Au moins, quand ils vivaient dans le chateau, leur lit etait au centre de la piece. Pourquoi c'est comme ca?)
(Qui dort dans le coin? Probablement Aaron.)
(Je jure cette fille va lui donner des cheveux gris 10 ans plus tot.)

ENOKI
(Je suis contente de ne pas avoir a dormir au milieu de la piece.)
(Rouler hors du lit sur le sol en pierre faisait tres mal.)
(Maintenant, je peux rouler en toute securite vers le mur ou vers Aaron.)
(Je suis tellement heureuse que ca ne le derange pas trop.)

AARON
(Maple ne sera pas contente quand elle verra cette piece.)
(Je me souviens quand elle etait plus calme...)
(MAintenat, c'est un peu frustrant de l'avoir avec nous.)
(Peut-etre qu'elle n'aurait pas du venir. Chaque fois que j'essaie de l'aider, elle ne fait que se plaindre et s'en prendre a moi.)
(Elle pourrait s'ennuyer de vivre ici et rentrer chez elle.)
(Ou peut-etre qu'elle a raison et que je vis dans la fantaisie d'Enoki.)
(Mais Enoki est le seul bonheur que j'aie depuis des annees.)
(Ont vas peut-etre changer, ou que quelque chose va changer...)

AUTRES (Je ne devrais pas entree sans etre invite...)

MAPLE
(Je vais surement jamais l'admettre, mais...)
(C'est super d'etre avec eux. Parfois, j'oublie a quel point ca me manque de vivre avec quelqu'un.)

ENOKI
(Parfois j'aimerais pouvoir remonter le temps pour me parler)
(Je ne pourrais jamais croire comment cette annee ce passe.)
(Et... je ne pense pas que mes parents sachent que je suis ici.)
(Je me demande ou ils pensent que je suis en ce moment.)

AARON
(J'ai besoin de trouver une place pour Maple.)
(Je ne pensais pas qu'elle se donnerait a font pour sa part...)
(Avec toute cette speleologie, on a reussi a atteindre le seuil de rentabilite.)
(Je suis surpris qu'elle n'a pas demandee un nouveau logement.)
(Peut etre qu'elle n'aime pas rester seule?)
(Et je ne veux pas construire une autre maison.)
(Je vais parler a cet Olivier et voir ce qu'il peut faire.)
(Il semble etre bon avec ses mains.)

LES AUTRES
(Oui, c'est une chambre.)

Olivier
(J'aime le soleil ici.)
(Je pourrais mettre des plantes.)

ELEANOR
(Ca me rappelle beaucoup la maison des parents de Vee.)
(J'espere que ce sont des gens de confiance.)

DIANA
(Ok, j'aime ces gens.)
(Ils me font me sentir propre.)

MAPLE
(Merci mon Dieu, le nouvel arrivant est cuisinier.)
(Manger la meme chose encore et encore ne seras pas aussi lourd quand je fais pas la cuisine.)
(Esperons qu'il a le sens de l'humour.)
(Ugh, je sais pas ce qui va pas chez moi.Je suis contente de le rencontrer?)
(Je vais perdre la carte si je deviens sociable...)

ENOKI
(Cette piece n'a pas change du tout.)
(Et si je deplacais le lit de l'autre cote?)
(Hmm, ca sera plus difficile de cacher nos vetements aux invites.)
(Je devrais recuperer tous... euh... ... mieux vaut le faire plus tard.)

AARON
(C'est la derniere chance a Maple de prendre la cabine.)
(Tant que Enoki est contente, Maple reste dans la maison.)
(Mais ca sera plus ma maison. Je sais pas quelle mouche l'a pique.)
(Utilise-t-elle sa fierte pour cacher la sangsue qu'elle est vraiment?)
(Et Enoki commence a realiser que je suis enerve.)
(Merde... Je sonne comme Maple.)
(Est-ce que tous les freres et soeurs sont comme nous?)
(J'aimerais pouvoir le demander a quelqu'un, mais je n'ai pas d'amis.)

OLIVIER
(L'anniversaire d'Aaron approche. Une plante serait un beau cadeau.)


DIANA
(J'aime le soleil ici.)
(Je pourrais mettre des plantes.)

LES AUTRES
(Je ne devrais pas fouiller ici.)

MAPLE                            He, c'est quoi ce livre?
AARON                            Oh, c'est a moi.
AARON                            Tu sais que j'aime pas beaucoup la fiction,
AARON                            Mais Enoki est parfois un peu tetue.
ENOKI                            Connais tu Yellow?
ENOKI                            C'est tellement amusant, J'ai demander a Aaron d'essayer.
MAPLE                            ...c'es tu un livre a images?
MAPLE                            Lis tu encore des livres avec des images?
ENOKI                            Mais c'est des images de cigarettes!
ENOKI                            Alors c'est pour les enfants et adultes.
MAPLE                            Hein, ca existe des livres comme ca?

This has a choice : the "/" signifies a branching point

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
MAPLE						Yeah, I'm not that thirsty.

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
(I'm a real scientist, living    off a corproate grant.)
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

ENOKI                            Oh, hey Maple, veux tu du jus?
MAPLE                            Quel  jus?
ENOKI                            C'est un secret.
MAPLE                            Je vais pas un liquide mystere.
ENOKI                            ....
ENOKI                            Allez, c'est du jus d'orange / POISON
MAPLE                            Tu ne pensais pas que je le decouvrirai en y goutant?
ENOKI                            Peut-etre?
MAPLE                            Merci, mais non.
//
MAPLE                            Venant de toi, c'est possible.
ENOKI                            Tu peux l'essayer pour le decouvrir.
MAPLE                            J'ai pas si soif.

(Il nous reste pas beaucoup de jus d'orange.)
(Je vais devoir aller en ville pour vendre nos produits.)
(Vendre un fruit pour en acheter un autre, comique.)
(Si seulement le jus de concombre avait meilleur gout...)

ENOKI                            EEEE! Tous mes amis se connaissent maintenant!
ENOKI                            Nous sommes un vrai un groupe enfin!
MAPLE                            Wow, je n'ai pas encore decide si-
MAPLE                            Si je reste ici, calme-toi.
SCOUT                            On doit tu attendre quelqu'un d'autre?
AARON                            Nous devrons attendre et voir quelqu'un arrive.

MAPLE                            Bon je les ai tous lus.
AARON                            Ca fait un moment que nous sommes pas alles en ville.
MAPLE                            Je me demande ce qui se passe la-bas.
ENOKI                            Si quelque chose de grave s'etait produit.
ENOKI                            Scout aurait dit quelque chose.
ENOKI                            Comme il est toujours sur Internet.
MAPLE                            Je pourrais lui demander de m'acheter des livres en ligne.
AARON                            Ce serait une bonne idee.


Vous voyez un tas de livres que vous n'avez jamais vus auparavant.
Mais aucun ne semble interessant... Pour l'instant.

MAPLE                            On devrais acheter un lecteur VHS.
AARON                            Vas-tu en acheter un?
MAPLE                            Oui, et beaucoup de cassettes.
ENOKI                            Oooh, peux-tu acheter le dernier film Time Raider? Je crois qu'il est sorti!
MAPLE                            Tu sais quoi, je vais acheter tout, SAUF celui-la.
ENOKI                            Aw... Je pensais que nous pourrions faire.
ENOKI                            ... Une soiree cinema?
MAPLE                            Ok,  PEUT-ETRE.

Tu souris en pensant a leur cuisine inferieure.
Ils deviendront certainement des clients reguliers.

AARON                            J'ai besoin de voir comment vont les autres.

LE JARDIN D'ENOKI                Tu touches, tu meur.

POINT DE COUPE DU BOIS           Ou on coupe le bois.

Hmmm... Ca semble etre une tache pour Enoki.

Hmmm... Ca semble etre une mission pour Aaron.

GROTTE DES CHAUVES-SOURIS agressive Attention : Contient des chauves-souris.

Je pense que Maple est la seule a pouvoir entrer en toute securite.

MAPLE                            Des plantes, hein?
MAPLE                            Y a-t-il un jardin aussi?
SCOUT                            Enfaite, je, euh-
SCOUT                            C'est pas vraiment pour les plantes
SCOUT                            Je suis un scientifique pour le sol.
MAPLE                            Un scientifique pour le sol?
SCOUT                            Il y a un scientifique pour beauc...
SCOUT                            Eh bien, pour tout, vraiment.
MAPLE                            Je vois ca.

ENOKI                            JE PENSE que c'est la bonne plante.
ENOKI                            C'est ma favorite.
SCOUT                            Veux-tu que je la coupe?
ENOKI                            Tu peux le faire?
SCOUT                            Je sais pas...
SCOUT                            J'etudie le sol, pas les plantes.
ENOKI                            Ca pourrait etre un fruit mysterieux!
SCOUT                            Et bien... C'est possible.

AARON                            Tu as fait des progres?
SCOUT                            Et oui!
SCOUT                            J'ai fait quelque chose de nouveau.
AARON                            Comment ca s'appelle?
SCOUT                            Je l'ai baptise 'Scout-Out'.
SCOUT                            C'est parfait pour les mauvaises herbes.
AARON                            Bougre, c'est tellement cool!
SCOUT                            Le seul tracas c'est que...
SCOUT                            Ca detruit tous les plantes.
AARON                            Ah, triste...

(Oh non, oh non, oh non...!)
(Je dois comprendre la formule aussi vite que possible.)
(Promettre de la terre magique aux investisseurs n'etait pas une bonne idee.)
(Si je me cache ici, ils ne me trouveront pas.)
(Mais je devrais enlever mon nom de la trappe ...)

MAPLE                            Toujours la meme routine?
SCOUT                            Oui, oui.
MAPLE                            Ils n'ont pas encore demande
MAPLE                            les resultats?
SCOUT                            Pas encore, mais je recois toujours
SCOUT                            un salaire chaque semaine.
MAPLE                            He, c'est parfait.
SCOUT                            Oh que oui.

(Maple regarde les plantes de temps en temps...)
(Au moins, elle a une opinion sur ca.)
(J'ai besoin que mon patron reponde vite a mes messages.)
(Mais avec mon bon salaire, je ne devrais pas trop le risquer.)
(Je dois juste m'assurer que je fais tous comme il le faut.)

(Beaucoup de plantes et de terres dans des bocaux.)
(Tu ne comprends pas vraiment, mais cela semble inoffensif.)

SCOUT                            He, euh... Maple?
SCOUT                            Puis-je poser une question?
MAPLE                            Bien sur?
SCOUT                            A... aime... Aime tu le tennis?
MAPLE                            J'aime le tennis // C'est tellement ennuyeux
MAPLE                            Pourquoi?
SCOUT                            Oh, rien, rien... J'ai juste...
MAPLE                            Tu veux jouer avec moi?
SCOUT                            J'ai toujours desire y jouer, mais j'ai personne avec qui jouer, tu comprend?
MAPLE                            Bien, trouve un terrain et je vais te montrer un truc ou deux.
SCOUT                            T'es serieuse?
MAPLE                            Bien sur.
SCOUT                            Merci!
//
SCOUT                            Oh, laisse faire.
MAPLE                            D'accord.

AARON                            Ecoute-moi une minute.
AARON                            Tu as un outil pour
AARON                            fabriquer des bunkers avec
AARON                            facilite, non? On peut faire-
AARON                            Une course sous-terrain!
SCOUT                            Oh, C'est une super idee!
SCOUT                            Je vais voir ce que je peux faire!

(Well, le moment est venu. Ils veulent que je montre mes echantillons.)
(Avec espoir, je vais garder mon travaille.)

(Beaucoup de plantes et de terres dans des bocaux.)
(Tu ne comprends pas vraiment, mais cela semble inoffensif.)

MAPLE                            He, regarde, un autre truc de nerds.
SCOUT                            Excusez-moi, mademoiselle!
SCOUT                            C'est les Time Raiders!
MAPLE                            Time... Raiders?
SCOUT                            Oui! Les aventures de
SCOUT                            Jahn-Jahn Gazebo et ses apprentis, Nexus et Ninjette!
MAPLE                            Ca sonne vraiment comme...
MAPLE                            As-tu deja ete en couple?
SCOUT                            Non, les filles me prenaient pour un nerd.
MAPLE                            Crois-moi, elles le pensent encore.

ENOKI                            Ah! C'est Time Raiders?
SCOUT                            Tu connais Time Raiders?
ENOKI                            'J'ai compris, Jahn-Jahn!'
SCOUT                            Enfin quelqu'un d'autre connais ca!
ENOKI                            Oui, Aaron m'a montre ca.
ENOKI                            J'aime le style de dessin.
ENOKI                            Veux-tu me le preter?
SCOUT                            Bien sur! J'ai presque fini.

AARON                            He, c'est pas Time Raiders?
SCOUT                            Oh que oui!
AARON                            Cool! As-tu vus le dernier?
SCOUT                            Pas encore.
SCOUT                            Quelque chose que j'ai appris avec ma 
SCOUT                            'Island Life', c'est que s'est difficile d'obtenir de nouvelles choses.
SCOUT                            Je pourrais continuer a lire sur le PC, mais ce n'est pas du tout pareil.
AARON                            Je comprends.

(Je dois finir pour pouvoir l'offrir a Enoki.)
(Mais la formule que j'ai promise... Je suis si proche.)
(Je vais devoir faire d'autres nuits blanches.)
(Encore un peu de temps et je vais reussir.)

SCOUT                            He, tu aimes vraiment lire des livres?
MAPLE                            Oh que oui.
SCOUT                            Penses-tu que je pourrais emprunter
SCOUT                            certain de tes livres?
MAPLE                            T'aimerais pas ca.
SCOUT                            Au moins, je veux essayer.
MAPLE                            Aimes-tu la romance?
MAPLE                            Des relations compliquees?
SCOUT                            Eh... Tu en a pas d'autres?
MAPLE                            Non, c'est ce que j'aime.
MAPLE                            Es tu mal a l'aise?
SCOUT                            ... Un peu.
MAPLE                            Continue a lire des bandes dessinees.

SCOUT                            He, Enoki?
ENOKI                            Oui?
SCOUT                            Peut-on parler de Maple?
ENOKI                            Oooh, a propos de quoi?
ENOKI                            TU AIMES Maple, hein?
SCOUT                            Oui?
ENOKI                            Nous le savons tous deja, hehe.
SCOUT                            Merde, c'est si evident?
ENOKI                            Mais elle est compliquee.
ENOKI                            Je l'ai presentee une fois a un garcon.
SCOUT                            Eh puis?
ENOKI                            Et ils sont sortis ensemble pendant un moment.
ENOKI                            Mais il l'enervait donc elle la quitte.
ENOKI                            Tu dois etre parfait pour elle.
SCOUT                            Et je ne le suis pas.
ENOKI                            Je ne connais personne de parfait.
SCOUT                            Eh bien, un homme peut rever.
ENOKI                            Ne change pas comment tu es.
ENOKI                            Tu n'as qu'a etre " toi-meme ".
SCOUT                            Je suppose que tu as raison.
ENOKI                            Tu trouveras la bonne.
SCOUT                            Ok. Merci, Enoki.
ENOKI                            De rien!

SCOUT                            Ehm... comment es-tu sorti avec
SCOUT                            Enoki pour la premiere fois?
AARON                            Je lui est acheter du cafe.
SCOUT                            Cafe, cafe... D'accord.
SCOUT                            J'ai pas, hmm...  De cafe...
AARON                            Tu veux sortir avec Maple?
SCOUT                            Well, je... Oui, j'aimerais bien.
AARON                            Tu pourrais essayer, mais c'est complique. Aucun garcon n'est
AARON                            assez bien pour elle.
SCOUT                            C'est peut-etre inutile d'essayer.
AARON                            C'est impossible de lui plaire.
AARON                            Crois-moi, je la connais bien.
SCOUT                            Que veux-tu dire?
AARON                            Son type est les perdants qui pensent qu'ils sont meilleurs qu'ils ne le sont. C'est vrai.
AARON                            Je l'ai aussi vu sortir avec d'autres types de perdants. Probablement que tu dois juste faire des efforts pour augmenter ta confiance?
SCOUT                            Eh bien, c'est un bon debut.
AARON                            Bonne chance avec elle.
SCOUT                            Merci.

(Si je peux convaincre Maple de donner une chance a ces bandes dessinees.)
(Alors nous pourrions avoir quelque chose en commun.)
(...Ca arrivera jamais.)

GUY                              Aimes-tu Time Raiders?
SCOUT                            Oui, un peu.
GUY                              Quand est-ce que tu recois les nouveaux?
SCOUT                            Diana les apporte chaque semaine.
GUY                              Quel soulagement, je pensais ne pas pouvoir suivre quand j'ai demenage ici.
SCOUT                            Mais on a une liste d'attente.
SCOUT                            Il faudra que tu attendes qu'Enoki termine, elle les adore.
GUY                              Et si je veux les lire en premier?
SCOUT                            Tu devras lui en parler.
GUY                              Je vais le faire.

(Les bandes dessinees du mois dernier trainent toujours sur le sol.)
(Elle collecte la poussiere.)

SCOUT                            He, tu aimes vraiment lire des livres?
MAPLE                            Oh que oui.
SCOUT                            Penses-tu que je pourrais emprunter
SCOUT                            certain de tes livres?
MAPLE                            T'aimerais pas ca.
SCOUT                            Au moins, je veux essayer.
MAPLE                            Aimes-tu la romance? // Aimes-tu le vintage?
MAPLE                            Des relations compliquees?
SCOUT                            Eh... Tu en a pas d'autres?
MAPLE                            Non, c'est ce que j'aime.
MAPLE                            Es tu mal a l'aise?
SCOUT                            ... Un peu.
MAPLE                            Continue a lire des bandes dessinees.


//
SCOUT                            Je pourrais commencer a les aimer.
MAPLE                            Je pense pas non.

SCOUT                            He, Enoki?
ENOKI                            Oui?
SCOUT                            Peut-on parler de Maple?
ENOKI                            Oooh, a propos de quoi?
ENOKI                            TU AIMES Maple, hein?
SCOUT                            Oui?
ENOKI                            Nous le savons tous deja, hehe.
SCOUT                            Merde, c'est si evident?
ENOKI                            Mais elle est compliquee.
ENOKI                            Je l'ai presentee une fois a un garcon.
SCOUT                            Eh puis?
ENOKI                            Et ils sont sortis ensemble pendant un moment.
ENOKI                            Mais il l'enervait donc elle la quitte.
ENOKI                            Tu dois etre parfait pour elle.
SCOUT                            Et je ne le suis pas.
ENOKI                            Je ne connais personne de parfait.
SCOUT                            Eh bien, un homme peut rever.
ENOKI                            Ne change pas comment tu es.
ENOKI                            Tu n'as qu'a etre " toi-meme ".
SCOUT                            Je suppose que tu as raison.
ENOKI                            Tu trouveras la bonne.
SCOUT                            Ok. Merci, Enoki.
ENOKI                            De rien!

SCOUT                            He, fais tres attention avec mon PC, Ca coute un bras.
MAPLE                            Je n'allais pas y toucher. Mais
MAPLE                            Maintenant, je suis curieuse...
SCOUT                            Attend, n'y touche pas!
MAPLE                            Je ne vais pas y toucher!
MAPLE                            Les nerds et leurs machines...

ENOKI                            He Scout, tu as un site Web?
SCOUT                            Oui! Mais il n'est pas tres beau.
ENOKI                            Je peux voir?
SCOUT                            Pas maintenant, je ne l'ai pas encore fini.
ENOKI                            Oh, d'accord.
ENOKI                            J'aimerais avoir mon propre site web.
ENOKI                            Ca semble amusant.
SCOUT                            Oh que oui!

AARON                            As-tu entendu parler du bug de l'an 2000?
SCOUT                            Bien sur.
AARON                            Rien n'est arrive?
SCOUT                            Rien de trop grave.
SCOUT                            Une application m'a donne un probleme plutot etrange.
SCOUT                            J'avais un programme pour organiser mes achats et ca a ajoute des tonnes de cire a soulier a la liste.
SCOUT                            Ca dois arriver le 5 mars 192000.
AARON                            C'est un peu long, hein?
SCOUT                            J'arriverais jamais a comprendre les bugs informatiques.

(J'ai obtenu mon diplome en tete de ma classe avec un GPA de 3,99.)
(Je suis maintenant un scientifique vivant d'une subvention d'entreprise.)
(J'ai un PC Castor 5000 a la pointe de la technologie.)
(Que je ne peux pas utiliser, car j'ai oublie mon propre mot de passe.)
(J'ai du mal a dormir la nuit en y pensant...)

(Ca a l'air tres cher...)
(Je ne devrais pas y toucher.)

(Cette formule verte rend les plantes enormes.)
(Je me demande ce qui arriverait si j'en avalais...)
(Peut-etre que j'aurais des pouvoirs lies aux plantes...)
(Ou je ferai juste mourir.)
(Mais ca vaut vraiment le coup d'essayer...)

SCOUT                            Attention!
SCOUT                            Beaucoup de ces choses sont
SCOUT                            SUPER TOXIQUE!

SCOUT                            Bonjour! Es tu Olivier?
OLIVIER                          Oui! Et tu es Scout, non?
SCOUT                            Oui, c'est moi. Bienvenue!
OLIVIER                          Cet endroit est incroyable!
SCOUT                            J'ai ete sincere dans l'annonce.
OLIVIER                          Vous etes scientifique?
SCOUT                            D'une facon, oui.
SCOUT                            Je fais un peu de tout.
OLIVIER                          Et vous vivez sous terre?
SCOUT                            J'ai une machine qui creuse des bunkers facilement.
SCOUT                            Je pourrais creuser jusqu'a des limites improbables.
OLIVIER                          Cool! He, tu viens diner chez les Tremblay?
SCOUT                            Oh que oui!
OLIVIER                          Cool! On se voit la-bas alors.

ELEANOR                          Bonjour, monsieur!
SCOUT                            Bonjour! Es-tu Eleanor?
ELEANOR                          Oui! Ravi de te rencontrer.
ELEANOR                          Cet endroit est incroyable!
SCOUT                            J'ai ete sincere dans l'annonce.
ELEANOR                          Etes-vous un magicien?
SCOUT                            D'une maniere oui.
SCOUT                            Je fais un peu de tout.
ELEANOR                          Et vous vivez sous terre?
SCOUT                            J'ai une machine qui creuse des bunkers facilement.
SCOUT                            Je pourrais creuser jusqu'a des limites improbables.
ELEANOR                          Comme c'est fascinant!
SCOUT                            Ah, merci!
ELEANOR                          On se voit plus tard au diner?
SCOUT                            Bien sur!
ELEANOR                          Merveilleux!

DIANA                            Bonjour! Hey, tu es Scout?
SCOUT                            Bonjour! Tu es Diana?
DIANA                            Oui! C'est un plaisir de te rencontrer!
DIANA                            Bougre, cet endroit est magnifique!
SCOUT                            J'ai ete sincere dans l'annonce.
DIANA                            Tu es scientifique ou quoi?
SCOUT                            D'une maniere oui.
SCOUT                            Je fais un peu de tout.
DIANA                            Et vous vivez sous terre?
SCOUT                            J'ai une machine qui creuse des bunkers facilement.
SCOUT                            Je pourrais creuser jusqu'a des limites improbables.
DIANA                            Wow, c'est cool!
SCOUT                            Merci!
DIANA                            Tu viens au diner?
SCOUT                            Bien sur!
DIANA                            Genial!

(J'aimerais pouvoir obtenir quelque chose qui me rendrait heureux.)
(Apres avoir passe tant de temps a etudier, me voila...)
(Et je ne sais pas. Je passe d'une chose a l'autre.)
(Je ne peux pas faire quelque chose sans vouloir le laisser a mi-chemin.)
(J'aimerais juste etre heureux la ou je suis maintenant, pour une fois.)

SCOUT                            Attention!
SCOUT                            Beaucoup de ces choses sont
SCOUT                            TOXIQUE MORTEL!
SCOUT                            Eh bien, vous le saviez deja.
SCOUT                            OU du moins, je l'espere.

SCOUT                            Bonjour! Tu es Guy?
GUY                              Oui. Et tu dois etre, Scout?
SCOUT                            Bienvenu! Tu aime ta cabine?
GUY                              Tu ne plaisantais pas a propos de la cuisine.
SCOUT                            Pas du tout!
GUY                              Il ne semble pas y avoir beaucoup de monde ici, et tu sais que je ne pourrai pas cuisiner beaucoup si je n'ai pas de clients.
GUY                              Combien de temps ca vas presndre jusqu'a ce que ce soit rempli de monde?
SCOUT                            Cela ne devrait pas prendre si longtemps.
GUY                              Tu es sur?
SCOUT                            Sans doute.
GUY                              Tres bien alors.

ENOKI                            Bonjour? Scout, es-tu la?
SCOUT                            Oui! Je suis ici! Ou est Aaron?
ENOKI                            Il est sorti pour voir comment vont les autres.
SCOUT                            Dieu merci. Salut Maple. Tu te sens bien?
SCOUT                            Tu as l'air fatiguee.
MAPLE                            Ferme la j'ai deja entendu asser de monde me dire que je
MAPLE                            semble fatiguee.
SCOUT                            Oh- D'accord...
SCOUT                            Hey Enoki, comment ca semble en haut?
ENOKI                            C'est bien, c'est juste... Il y a un bruit etrange.
ENOKI                            Aaron a eu peur et voulait que nous allions en securitee.
SCOUT                            Je lui fais confiance sur ca.

AARON                            Qu'est-ce qui se passe dehors?
SCOUT                            C'est Rufus. Je pense qu'il a une indigestion alimentaire.
ENOKI                            Hehe, ca m'arrive aussi apres avoir mange la nourriture de Guy.
SCOUT                            Non, ca pourrait etre grave. C'est peut-etre lie a mes recherches.
AARON                            Oh, alors le scientifique va nous reveler ce qu'il fait dans ce mysterieux bunker depuis quelques mois?
SCOUT                            Je suis un scientifique du sol, mais la verite, je fais aussi des recherches sur les plantes.
ENOKI                            Vraiment!
OLIVIER                          Et pourquoi tu n'a rien dit?
SCOUT                            Je ne pouvais pas, c'etait confidentiel.
SCOUT                            Vous voyez, il y a une certaine plante qui pousse ici et beaucoup de gens crois qu'elle est magique. Elle vous donne des visions.
ENOKI                            Comment les champignons?
SCOUT                            Non, eux donnent des visions aleatoires, la plante donne la meme vision a tous. C'est pourquoi on l'etudie. C'est pas juste un bad trip.
SCOUT                            Chaque personne qui en prend agis differemment, mais c'est rien de chimique. Comme si ce qu'il voyait etais quelque change qui change-
SCOUT                            leur vie. Et ils deviennent quelque de differents apres l'experience.
ELEANOR                          Et que voient-ils?
SCOUT                            Je ne sais pas. Les personnes concernees preferent garder le silence.
SCOUT                            Les personnes qu, en consomme, on un cercle bleu dans les yeux. Ca ne dure pas pour toujours, mais on peut le remarquer pour un moment.
SCOUT                            J'ai regarde la video de Rufus et bien sur, il avait un cercle bleu.
AARON                            Donc il est devenu un super-vilain ou quoi?
SCOUT                            Je sais pas. Rufus n'est pas tres... grand., tu sais? Peut-etre-

SCOUT                            Euh... Je pense qu'il y a quelqu'un a la porte.
AARON                            J'ai ma hache a portee de main.
SCOUT                            He, vous vous rappelez de ma machine a bunker?
AARON                            Oui...?
SCOUT                            Ecoutez-moi. Et si on creusait un tunnel qui va hors de l'ile? En plus, je voulais deja en faire un jusqu'au rivage.
SCOUT                            (Je souhaitais garder ca pour l'Expo Scout, mais, euh...)
SCOUT                            (Mais j'ai plus de choix maintenant.)
ELEANOR                          C'est securitaire?

SCOUT                            Allons-y.
ENOKI                            Allons-y!

Vous regardez l'oeuvre d'art.
Et par consequent....
L'oeuvre d'art vous observe.
L'art c'est etrange.

- PLUS DE MAISONS PLUS LOIN -

MAPLE                            Je devrais peut-etre aller chez Scout.

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
MAPLE                            (What was Scout thinking invitingthese weirdos?!)

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
ELEANOR                          Vee and I were so excited to hearabout this island.
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
SCOUT                            He's got magic powers and a- wellmaybe I should just let you
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
ELEANOR                          Don't you have some vegetables toprune? I need to get started
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
ELEANOR                          I have set up my room, and we nowhave a crystal ball room!
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
GRAND-MERE CORINNE               This greenhouse is still quite   nice, was it moved?
OLIVIER                          Oh.. Well, I was told that it wastransported from inland.
GRAND-MERE CORINNE               Well, you see, I once owned this greenhouse, young man.
GRAND-MERE CORINNE               I don't see any point in having  ambiguity; I am a ghost.
OLIVIER                          A ghost???
GRAND-MERE CORINNE               It seems I am doomed to haunt    this greenhouse forever.
OLIVIER                          My apologize, that seems... it   seems like a terrible fate.
GRAND-MERE CORINNE               Would you consider it horrible tospend an eternity here?
OLIVIER                          Now that I think about it.. I    suppose not.
OLIVIER                          It's where I spend most of my    life anyway.
GRAND-MERE CORINNE               I see you enjoy taking care of   these plants, son.
GRAND-MERE CORINNE               Before I leave, I will remind youof one wisdom.
GRAND-MERE CORINNE               Even if your care of these plantsseems meaningless,
GRAND-MERE CORINNE               Wonderful things come to the     diligent.
GRAND-MERE CORINNE               It was very nice to meet you.    Until next time!
    
OLIVIER                          O-Oh! Excuse me, ma'am. Where didyou come from?
GRAND-MERE CORINNE               This greenhouse is still quite   nice, was it moved?
OLIVIER                          Oh.. Well, I was told that it wastransported from inland.
GRAND-MERE CORINNE               Well, you see, I once owned this greenhouse, young man.
GRAND-MERE CORINNE               I don't see any point in having  ambiguity; I am a ghost.
OLIVIER                          A ghost???
GRAND-MERE CORINNE               It seems I am doomed to haunt    this greenhouse forever.
OLIVIER                          My apologize, that seems... it   seems like a terrible fate.
GRAND-MERE CORINNE               Would you consider it horrible tospend an eternity here?
OLIVIER                          Now that I think about it.. I    suppose not.
OLIVIER                          It's where I spend most of my    life anyway.
GRAND-MERE CORINNE               I see you enjoy taking care of   these plants, son.
GRAND-MERE CORINNE               Before I leave, I will remind youof one wisdom.
GRAND-MERE CORINNE               Even if your care of these plantsseems meaningless,
GRAND-MERE CORINNE               Wonderful things come to the     diligent.
GRAND-MERE CORINNE               It was very nice to meet you.    Until next time!

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
GRAND-MERE CORINNE               This greenhouse is still quite   nice, was it moved?
OLIVIER                          Oh.. Well, I was told that it wastransported from inland.
GRAND-MERE CORINNE               Well, you see, I once owned this greenhouse, young man.
GRAND-MERE CORINNE               I don't see any point in having  ambiguity; I am a ghost.
OLIVIER                          A ghost???
GRAND-MERE CORINNE               It seems I am doomed to haunt    this greenhouse forever.
OLIVIER                          My apologize, that seems... it   seems like a terrible fate.
GRAND-MERE CORINNE               Would you consider it horrible tospend an eternity here?
OLIVIER                          Now that I think about it.. I    suppose not.
OLIVIER                          It's where I spend most of my    life anyway.
GRAND-MERE CORINNE               I see you enjoy taking care of   these plants, son.
GRAND-MERE CORINNE               Before I leave, I will remind youof one wisdom.
GRAND-MERE CORINNE               Even if your care of these plantsseems meaningless,
GRAND-MERE CORINNE               Wonderful things come to the     diligent.
GRAND-MERE CORINNE               It was very nice to meet you.    Until next time!
    
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

- PUITS A SOUHAIT -               NE FONCTIONNE PAS MAIS N'HESITEZ PAS A L'UTILISER SI VOUS LE VOULEZ
Les rochers devant vous ne permette meme pas de prendre la vue.
Si vous pouviez escalader les rochers, vous pourriez lancer une piece pour faire un voeu.
L'etang aurait pu etre mieux amenagee.

 - LA MAISON DE LANDRY -

- DIANA -
C'est le nom de la maison ou du proprietaire?

- LA MAISON DE QUELQU'UN -
C'est inhabite.

- MAISON DE GUY -
La maison d'un certain Guy.

MAPLE                            Oh, he. Tu es Eleanor?
ELEANOR                          Oui! Enchante de faire votre connaissance.
MAPLE                            Egalement. Je ne voudrais pas t'offenser, mais tu sembles...
MAPLE                            Un peu demodee?
ELEANOR                          Oh, c'est une habitude.
ELEANOR                          Ca fait du bien d'etre a nouveau loin de la ville. J'avais oubliee comment j'aimais etre entouree d'arbre.
MAPLE                            Je comprends. Tu es son mari, j'imagine?
OLIVIER                          Oui, je suis Olivier.
ELEANOR                          Bien qu'il soit tres reserve, c'est quelqu'un de tres attentionne.
ELEANOR                          Je l'ai rencontre dans un jardin et il m'a appris a lire.
OLIVIER                          Elle est tres speciale pour moi. Elle m'a pratiquement sauve la vie.
MAPLE                            Oh, comment?
OLIVIER                          C'est pas quelque chose d'important-
ELEANOR                          De ma mere.
MAPLE                            Ah, je comprends, he.
ELEANOR                          Vraiment? Elle allait drainer tout son sang pour un rituel.
MAPLE                            Je... Hmm, eh bien, d'accord. Ce... n'etait pas ce a quoi je m'attendais.
MAPLE                            Ravi de vous rencontrer, je suppose?
ELEANOR                          Bien sur! Je vais preparer une tarte pour toi en guise de "merci".
MAPLE                            C'est bon, je demanderai juste de pas utiliser d'ingredients bizarres.
MAPLE                            (A quoi pensait Scout en invitant ces cingles?!)

ENOKI                            Soyez les bienvenus! Je m'appelle Enoki! Ravie de vous rencontrez.
ELEANOR                          Bonjour! Enchantee de faire votre connaissance.
OLIVIER                          Bonjour!
ELEANOR                          Je suis Eleanor, et voici mon mari Olivier.
ENOKI                            Tu as une belle robe! Ou l'as-tu achete?
ELEANOR                          Ah! Je l'ai fait moi-meme. J'aime beaucoup la votre aussi!
ENOKI                            Eh bien, c'est merveilleux!
ENOKI                            Je pense qu'on a la meme taille, on pourrait faire des echanges!
OLIVIER                          Scout a dit que vous faisiez partie de la royaute?
ENOKI                            Ah oui! C'est notre petit royaume, mais nous sommes pas cruel.
ENOKI                            Je suis la reine la plus calme et la plus amicale que vous rencontrerez.
ENOKI                            Voulez-vous devenir le duc et la duchesse de notre royaume?
ELEANOR                          Je... non, merci. Je ne sais meme pas ce que veulent dire ces titres.
OLIVIER                          Merci, en tout cas.
ENOKI                            Bien sur! N'importe quand!

AARON                            Bienvenue! Olivier et Eleanor, je suppose?
ELEANOR                          Oui oui!
OLIVIER                          Etes-vous le 'roi' de cette ile?
AARON                            Scout a dit ca? Je suppose que oui..
AARON                            J'ai jamais termine mes etudes secondaires, donc je suis pas fait pour grand chose, mais je ne voulais pas passer ma vie dans une usine.
AARON                            Ma femme, Enoki, et moi avons eu l'idee d'acquerir un terrain pour vivre par nous-memes. La "royaute" etait son idee. Elle etait si
AARON                            mignonne quand elle a demande que j'ai dit oui.
AARON                            Elle vous a surement offert aussi des roles aristocratiques.
OLIVIER                          Oh, Aaron? Merci d'avoir degage la zone pour la serre. Maintenant, je peux partager ce que j'y cultive.
ELEANOR                          Et j'adore cette cabine! Cela me rappelle ma maison natale.
ELEANOR                          Vee et moi etions ravis de voir l'ile.
AARON                            Et nous sommes heureux que vous ayez decide de venir ici!
AARON                            Si ma petite soeur vous donne du fil a retordre...
AARON                            Je vous promets qu'elle ne le fait pas expres.
AARON                            Vous pouvez passer ce soir pour diner ensemble.
OLIVIER                          Encore une fois, je vous remercie sincerement.
AARON                            Nous sommes une famille maintenant, tu peur dire tu.

SCOUT                            Salut tout le monde! Je suis Scout,Je vous ai parle sur Internet?
OLIVIER                          Ah! Enchante de faire votre connaissance.
ELEANOR                          Oh... Mais quand j'ai vu ta photo sur internet j'ai cru que tu etais...
SCOUT                            J'etais quoi?
ELEANOR                          Je pensais que tu etais un squelette.
SCOUT                            Oh, c'est juste une photo d'un personnage que j'aime bien.
SCOUT                            C'est un squelette d'une bande dessinee appelee Seemore.
SCOUT                            Il ades pouvoirs magiques, je peux peut-etre vous preter la bande dessinee.
SCOUT                            Je vous assure que c'est tres amusant et interessant.
ELEANOR                          C'est quoi un bande dessinee?
SCOUT                            Je... J'ai jamais pense devoir repondre a cette. C'est comme des livres mais ils ont des images et-
ELEANOR                          Ca sonne bien!
OLIVIER                          Eleanor a grandi dans une secte, elle connait pas grand-chose au monde exterieur. C'est l'une des raisons pour lesquelles nous voulions 
OLIVIER                          demenager ici, pour avoir une petite pause de sa famille elargie.
SCOUT                            Ah. Eh bien. Je vous souhaite la bienvenu sur l'ile, je suppose.
SCOUT                            Reine Enoki a mon dernier numero de Time Raiders, mais quand elle auras finit, je vous laisserai le regarder.
ELEANOR                          Merci!

OLIVIER                          Eleanor, pourquoi as-tu allume la cuisiniere? Nous n'allions pas diner avec les Tremblay ce soir?
ELEANOR                          Oh, bien sur, mais je n'ai pas pu m'en empecher.
ELEANOR                          Jee n'ai pas vus un four comme ca depuis mon enfance.
ELEANOR                          Alors j'ai voulu essayer de me faire des toasts.
OLIVIER                          Que penses-tu de cet endroit?
OLIVIER                          Il n'y a pas beaucoup de monde, tu vas pas te sentir un peu seul?
ELEANOR                          Et toi? Pense-tu que tu vas te sentir seul?
OLIVIER                          J'aimerais que mon grand-pere puisse nous voir en ce moment.
OLIVIER                          Je pense qu'il serait tres fier de toi.
ELEANOR                          Peut-etre qu'il nous regarde depuis le ciel.
ELEANOR                          Et ma mere a peut-etre changee la-haut et elle pense que tu es un gars bien maintenant.
OLIVIER                          Nous n'aurons jamai la reponse, mais je sait que je ne me sent pas seul.
OLIVIER                          Je ne me sens plus seul depuis que tu es avec moi.
ELEANOR                          Vee, j'espere que nous n'arreterons jamais de ressentir cela.
ELEANOR                          J'ai vu comment mes parents sont devenus et j'ai l'impression de vieillir. Je sais qu'une fois que nous aurons nos enfants...
OLIVIER                          Comment va ta soeur?
ELEANOR                          Elle est toujours epuisee. Elle plaisante sur ses cheveux gris, mais, elle est differente.
ELEANOR                          Les choses qui l'enervait sont si loin maintenant.
OLIVIER                          Et s'il nous arrivait la meme chose? Nous devrons etre patient.
ELEANOR                          Ce sera etrange d'avoir des amis maries a notre age. Pense-tu que
ELEANOR                          Diana sera jalouse?
OLIVIER                          Je pense qu'elle va s'amuser ici. S'il te plait relax!
ELEANOR                          Je suppose que tu as raison, Vee.

DIANA                            Oh super! J'adore cet endroit, c'est tres cosy.
DIANA                            J'espere que vous derange pas que je passe tous mon temps ici.
ELEANOR                          Bien sur que non! Tant que cela ne te derange pas de nous aider parfois.
OLIVIER                          Rappeles toi, vivre ainsi signifie que nous devons travailler dur.
OLIVIER                          Tu devras probablement passer beaucoup de temps a couper du bois, ou travailler dans le jardin a arroser et desherber.
ELEANOR                          Tu etais interesser a travailler pour le capitaine du navire?
DIANA                            Oh oui, je vais aller a la jetee aujourd'hui.
DIANA                            Je serai capitaine d'un navire avant que tu ne le saches!
ELEANOR                          Je sais que tu peux faire tout ce que tu veux, Diana!
OLIVIER                          Ce n'est pas ce que tu pensais faire a 22 ans, hein?
DIANA                            Eh bien, c'est pas comme si j'avais une idee claire avant.
DIANA                            Demenager sur une ile est quelque chose d'inattendu pour tout le monde. Non?
OLIVIER                          Je pensais passer le reste de ma vie a jardiner.
ELEANOR                          Je suis toujours en vie et Vee est avec nous, je ne peux pas en demander plus.
DIANA                            Oui... J'espere que les choses resteront aussi bonnes pendant longtemps.

MAPLE                            Bonjour, les gars.
ELEANOR                          Bonjour, Maple! Veux tu du ragout? Il est frais.
MAPLE                            Bien sur que j'en veux, ton ragout est fantastique.
OLIVIER                          Diana nous a emmenee un nouveau jeu de societe de la ville.
OLIVIER                          Pourrais-tu demander au autre s'ils souhaitent jouer ce soir?
MAPLE                            Mais pas moi? Haha.
MAPLE                            Hey, euh... Desole pour la partie de la semaine derniere.
ELEANOR                          C'est bon, Maple. C'es tres facile de s'enerver sur des jeux.
MAPLE                            En plus votre cabine semble avoir cesse de sentir la fumee.
ELEANOR                          As-tu essaye le nouveau gumbo des iles?
MAPLE                            Me demandes-tu si j'ai peur de l'essayer? Nan, pas pour le moment.
MAPLE                            Quoi qu'il en soit, il n'y a rien que plus de Tabasco ne peux pas regler.
MAPLE                            Je sais que je ne viens pas vous souvent mais...
MAPLE                            Je tiens a vous remercier pour les ingredients. Vous etes des anges.
OLIVIER                          Merci pour ton travail acharne. Je n'avais pas completement confiance avec cette histoire d'ile.
OLIVIER                          C'est presque comme si vous aviez un porte-bonheur.
MAPLE                            Oui... D'une maniere ou d'une autre, Enoki obtient tout ce qu'elle veut.
MAPLE                            Ce n'est qu'une question de temps avant que quelque chose ne tourne mal et qu'elle n'aille pas ce qu'elle souhaite
OLIVIER                          Je vois. Eh bien, si tu as besoin de quelque chose de notre part, tu n'as qu'a demander.
MAPLE                            Pareil!

ENOKI                            Salut!! Comment vas-tu aujourd'hui?
ELEANOR                          Nous allons tres bien! Veux-tu du ragout?
ENOKI                            Je mentirais si je disais que quelqu'un n'en reclamait pas, hehe.
OLIVIER                          Tu viens jouer ce soir?
ENOKI                            Je ne manquerais ca pour rien au monde!
ELEANOR                          Avez-vous deja rencontre le nouvel insulaire?
ENOKI                            Ne dis rien a Maple...
ENOKI                            mais je pense que son gombo est meilleur que le sien.
ENOKI                            Tu dois me promettre de ne PAS dire ca a Maple.
ELEANOR                          Mes levres sont scellees.
ENOKI                            He, vous avez une machine a coudre par ici?
ELEANOR                          Oui.
ENOKI                            Tu as dit que tu fabriques tes propres vetements, oui? Tu, euh...
ENOKI                            Ca te derangerait-il de me donner des lecons?
ELEANOR                          Pas du tout! C'est avec plaisir que je t'enseignerai.

AARON                            Bonjour! J'ai entendu parler de jeux de societe ce soir.
ELEANOR                          Oui! Nous aimerions l'installer a l'exterieur sous un arbre.
ELEANOR                          J'ai fait une courtepointe assez grande pour que tout le monde puisse s'y glisser.
AARON                            Ca va etre dehors cette fois donc Maple ne bruleras rien d'important, oui?
OLIVIER                          Oui, ha ha.
ELEANOR                          Nous avons aussi fait du ragout, au cas ou tu aurais envie de manger quelque chose.
AARON                            J'ai deja mange le reste du gombo a Maple, mais merci!
AARON                            Parlant de nourriture. Bien qu'il soit timide, Guy est un bon garcon.
AARON                            Je suis ravi que plus de gens viennent sur l'ile.
OLIVIER                          Petit a petit cela devient un vrai village.
AARON                            Ouais, je pensais la meme chose.
OLIVIER                          Ca va, Aaron? Tu as le visage pale.
AARON                            Ouais, je pensais juste que Maple et avons des problemes recemment.
OLIVIER                          Comment-c?
AARON                            Elle veut pas changer de maison, mais elle va devoir le faire.
OLIVIER                          Pourquoi tu ne lui parles pas? Tu es le roi nom?
AARON                            Je peux et je devrai. Elle est just tres difficile.
AARON                            Elle n'arrete pas de changer entre vouloir etre super independente et devenir une sangsue.
OLIVIER                          Tu devrais discuter ca avec elle, pas avec nous.
AARON                            Oui tu as raison.


SCOUT                            Salut tout le monde! Scout est arrive!
ELEANOR                          Bonjour! Veux-tu du ragout?
SCOUT                            Merci, mais j'ai mange il y a... un moment?
SCOUT                            Merde, j'ai rien mange de la journee. Je vais prendre du ragout!
ELEANOR                          Hehe, pas de probleme, prend la portion que tu veux.
SCOUT                            Avez-vous vu le reportage de Scout TV ce matin?
ELEANOR                          Oh, nous-autres on a pas de television.
SCOUT                            C'est vrai... Je suis desole, j'avais oublie.
SCOUT                            Ma transmission a ete piratee de toute facon.
OLIVIER                          pirate? Par qui?
SCOUT                            Aucune idee. Les Tremblay ne semblent pas trop inquiets de toute facon.
ELEANOR                          Tu viens jouer avec nous-autres ce soir?
SCOUT                            Je vais essayer de venir, j'ai still du travail devant moi.
SCOUT                            Alors je vais te revenir avec ca.
OLIVIER                          Pas de probleme, on vous garde une place.
SCOUT                            Merci!
ELEANOR                          De rien!

OLIVIER                          Alors ton anniversaire c'est dans une semaine...
ELEANOR                          Oui?
OLIVIER                          J'aimerais faire une surprise, mais je ne veux pas te decevoir avec-
ELEANOR                          ...
OLIVIER                          ... Tu veux que je te surprenne?
OLIVIER                          ...
OLIVIER                          Pense-tu encore a la ceremonie?
ELEANOR                          C'est une nuit que je n'oublierai jamais.
ELEANOR                          Je ne peux pas dire si c'est bon ou mauvais malheureusement.
ELEANOR                          Tu m'as donne le seul cadeau que j'avais besoin toute ma vie
OLIVIER                          Mais tu ne te plaindrais pas si j'achetais une nouvelle machine a coudre.
ELEANOR                          ...
OLIVIER                          Je confirme pas que c'est ton cadeau mais...
ELEANOR                          Tu n'as pas des legumes a coupe? je dois commencer
ELEANOR                          pour les mettre en conserve pour l'hiver.
OLIVIER                          D'accord, d'accord, c'est juste... Eh bien, tant pis.

DIANA                            Les gars, nous devons parler.
OLIVIER                          Il y a un probleme?
DIANA                            Quelqu'un a pirate la chaine de Scout ce matin.
DIANA                            Je pense que c'etait un Mons d'Plonj, il a menace l'ile.
ELEANOR                          O-Oh.. Oh non..  Il n'etait pas avec les sorcieres quand meme?
ELEANOR                          Vee, nous ont-ils trouves?
DIANA                            Non, il avait juste l'air d'un abruti. Et Maple semble le connaitre.
DIANA                            Les Tremblay ne sont pas inquiets.
ELEANOR                          Oh... Dieu merci...
DIANA                            As-tu rencontre le gars au Nord, Cesar?
DIANA                            Il parait bizarre, mais Enoki lui fait confiance. Il a un magasin en plus . Et l'autre garcon, Guy, cuisine tres bien.
OLIVIER                          He, El, calme-toi, tu as l'air d'etre au bord de la crise.
ELEANOR                          Desole... desole...
DIANA                            He, Eleanor, ca va aller. Veux tu venir chez moi?
DIANA                            Nous pouvons nous detendre et manger des collations importees.
DIANA                            Ouais, ca a l'air amusant. Merci.

ELEANOR                          Bonjour! Vous devez etre Guy.
GUY                              Oui. Je suis Guy. Guy Pizza.
ELEANOR                          Guy... pizza?
GUY                              Le nom etait plus drole quand je travaillais a la pizzeria.
OLIVIER                          Eh bien, en tout cas, vous etes le bienvenu sur l'ile!
GUY                              Ravi de vous rencontrer. Je dois still finir de ranger mes affaires.
GUY                              J'ai toujours voulu une cuisine tres grande et je vais en faire bon usage, vous verrez.
ELEANOR                          On va jouer a un jeu de societe ce soir.
ELEANOR                          Veux-tu nous rejoindre?
GUY                              J'adorerais, mais en ce moment, je suis preoccupe avec ma cuisine.
ELEANOR                          Je vois... J'espere que tous ira bien avec ta cuisine.
GUY                              Oh, j'espere. J'espere.

ELEANOR                          Que se passe-t-il dehors?
AARON                            Je sais pas, mais suivez-moi, on va au bunker de Scout etpour attendre que les choses se calment.
AARON                            Ou est Diana?
OLIVIER                          Elle est partie naviguer avec Guy et ne reviendra que plus tard.
AARON                            Dieu merci. Suivez-moi, sortons d'ici.

    C'est la bibliotheque d'Eleanor.

    La porte est fermee.
    Vous ne devriez pas fouiner chez les autres.
    
MAPLE                            He! Tu es Diana?
DIANA                            Salut! Cool une autre rousse!
MAPLE                            Oh, mes cheveux ne sont pas roux, c'est plutot blond miel.
MAPLE                            Je suis une elfe, donc parfois ils semblent un peu d'orange.
DIANA                            Oh, je vois? Mais pourquoi...
MAPLE                            Pourquoi mes oreilles sont ronde?
DIANA                            Je ne veux pas te rendre mal a l'aise.
MAPLE                            C'est pas un probleme. Elles ont ete coupees quand j'etais bebe.
MAPLE                            Je m'appelle Maple, au fait. Maple Tremblay.
DIANA                            Heureuse de te rencontrer!
DIANA                            Ces cabines sont confortables! C'est ton grand frere qui les faits?
MAPLE                            En partie. Je sors occasionnellement chercher des pierres precieuses dans les grottes.
MAPLE                            Nous gagnons assez pour bien vivre ici.
DIANA                            Vie tu dans le camper?
MAPLE                            Oui, je dors sur le sofa.
DIANA                            Et tu ne veux pas de cabine? L'une parais vide.
MAPLE                            Enfaite, Aaron et Enoki desirent faire un chateau.
MAPLE                            Donc, je prevois de garder le camper quand se sera fait.
DIANA                            Alors... Cette ile, est-ce un vrai pays?
MAPLE                            Si en pense que ca l'est, ca dois l'etre non?
DIANA                            Est-ce si facile de creer un pays?
MAPLE                            On verra s'il y a une guerre, en passant ravit de te connaitre
DIANA                            Ehm, oui, ravie de te rencontrer aussi!
aise

ENOKI                            He! Tu es Diana? Je suis Enoki Tremblay!
DIANA                            Enchantee de faire ta connaissance!
ENOKI                            Tu te sens bien ici?
DIANA                            C'est fou, je suis pas encore sur que c'est reel.
DIANA                            C'est trop incroyable pour etre vrais.
ENOKI                            Je suis tres chanceuse, quand je veux que quelque chose se passe...
ENOKI                            La vie fais tout pour que je l'aille, et je l'ai demandee.
ENOKI                            J'ai entendu dire que tu etais souvent avec Capitaine Nicholas?
DIANA                            Oui! Il cherche quelqu'un pour reprendre son flambeau.
DIANA                            Un jour, je conduirai le navire partout dans le lac Superieur.
ENOKI                            Ca a l'air amusant! Tu devras nous laisser venir des fois.
ENOKI                            Si tu as besoin de quoi que ce soit, dit le nous.
DIANA                            D'accord!

DIANA                            Bienvenu! Tu es Aaron Tremblay, non?
AARON                            Bienvenue! Comment ca vas dans ta cabine?
DIANA                            C'est super! Trop beau pour etre vrai.
DIANA                            Aujourd'hui, j'aurai ma premiere instruction de conduite du bateau.
DIANA                            Connais-tu  capitaine Nicholas?
AARON                            En vrai, je passe la plupart de mon temps a couper du bois.
AARON                            Mais il semble etre un bon gars d'apres ce que j'ai compris.
AARON                            Je resterai pas longtemps, je suis juste venu voir comment tu allais.
AARON                            Dis-moi si tu as besoin de quoi que ce soit, d'accord?
DIANA                            Bien sur! Merci beaucoup!

SCOUT                            He! C'est moi, Scout. Je voulais juste me presenter.
DIANA                            Oh, ravie! Je sais toujours pas si c'est reel...
DIANA                            Je suis contente de ne pas avoir... Eh bien... ete tuee ou pire.
SCOUT                            J'avoue que je suis ici que depuis peu de temps aussi.
SCOUT                            J'ai demenage ici d'une ile qui est pas trop loin.
SCOUT                            Mais ensuite j'ai rencontre les Tremblay et j'ai decide de me joindre.
SCOUT                            C'etait pas si facile de faire un nouveau bunker, mais ca valait le coup. Je me sens bien ici.
DIANA                            Eh bien, tu sembles aller bien. Tu es un scientifique?
SCOUT                            Oui, c'est drole. Parce qu'une entreprise m'a aussi envoye ici pour faire des experiences sur l'ile, sans beaucoup de details.
DIANA                            As-tu decouvert de quoi de cool?
SCOUT                            J'ai cree un appareil qui fait des bunkers rapidement.
SCOUT                            Je sais pas quoi faire d'autre avec, mais ca a du potentiel.
DIANA                            He, si tu en as envie, pourrais-tu me construire un bunker aussi?
SCOUT                            Bien sur, j'adorerais!

DIANA                            He, Vee! Contente de te voir dans ma /nouvelle cabine/!
OLIVIER                          Il ne t'a pris qu'une journee pour la remodeler comme
OLIVIER                          ton ancienne maison, hein?
DIANA                            Si tout va bien, cette cabine sera comme mon ancienne maison.
OLIVIER                          Tout dependra si nous pouvons faire confiance au autres.
OLIVIER                          Tu as de quoi te defendre si les choses tournent mal?
DIANA                            Oui, je porte un fusil a fusee eclairante.
DIANA                            Bien que j'espere ne pas avoir a l'utiliser.
OLIVIER                          J'espere moi aussi. Ils ont l'air de gens sympas.
OLIVIER                          Ou du moins ils n'on aucun interet a nous sacrifier.
DIANA                            Hehe, je te le dis. Si quelqu'un de la famille d'El se presente,
DIANA                            Appelle-moi tout de suite, d'accord?
OLIVIER                          Bien sur, bien sur.

ELEANOR                          Ca ressemble a ton ancienne chambre!
DIANA                            Bien sur, tu me prend pour qui, hi hi.
ELEANOR                          J'adore ca, c'est tellement confortable.
ELEANOR                          Dit moi si tu as besoin de quoi que ce soit,
ELEANOR                          J'ai decore ma chambre, et j'ai installe la boule de cristal. Je pratique toujours l'invocation.
DIANA                            Et tu sur que l'utilisation de ta magie n'attireras pas... euh... les sorcieres ?
ELEANOR                          Je suis sur. Si tout se passe bien, nous pourons meme inviter ma famille. J'aimerais leur montrer cet endroit relaxant.
DIANA                            Nous verrons, on a pas eu une vie tranquille jusqu'ici.
DIANA                            Au fait, as-tu deja parle au Tremblay?
DIANA                            On dirait qu'il en a un pour nous trois.
DIANA                            Il y a une fille rousse et deux... fermiers?
DIANA                            Enoki est mignone, mais tu l'es encore plus!
ELEANOR                          Ah, merci!
DIANA                            Je ne peux pas m'empecher d'etre sur mes gardes, mais je pense que tout ira bien ici.
ELEANOR                          Je pense la meme chose.

MAPLE                            Diana! He!
DIANA                            He, Maple! Comment tu vas?
MAPLE                            Bien, je suis entrain de m'ennuyer .
DIANA                            As tu regarder Scout TV ce matin?
MAPLE                            Celui que Rufus a pirate? C'est un idiot, tout ira bien.
MAPLE                            Peut-etre que maintenant il pense qu'il est un super mechant ou quelque chose.
DIANA                            Des gars comme ca me font rire aux eclats, vraiment. Haha!
MAPLE                            En passant. Previens-moi si tu le vois dans le coin.
MAPLE                            Je vais essayer de lui parler.
DIANA                            Okay.
DIANA                            Que fais tu dernierement?
MAPLE                            As-tu vu Scout? Ce pauvre garc a vraiment son oeil sur moi..
MAPLE                            C'est un gars adorable, mais je devrai lui faire comprendre bientot qu'il est pas mon genre.
DIANA                            Fille, je t'envie pas, haha. Cest quoi ton type?
MAPLE                            J'aimerais quelqu'un qui est calme et qui me fait sentir excitee.
MAPLE                            Tous les garcons agissent comme si j'etait une deesse et je n'aime pas ca. Je pourrais faire un barbecue avec eux si je le voulais.
DIANA                            Heh, peut-etre que tout le monde te traite comme ca parce que tu finis par leur faire peur.
MAPLE                            Je devrais trouvee un autre elfe du feu.
DIANA                            Nous sommes loin dans le sud-est, il en a pas beaucoup.
MAPLE                            Ouais, je vais continuer a chercher, meme si cette ile est petite.
DIANA                            Bonne chance, ha ha. Prends bien soin de toi, Maple.

ENOKI                            He fille!
DIANA                            Enoki, ma cherie! Veux-tu une collation?
ENOKI                            Comme toujours.
DIANA                            Haha, j'aime ca comme ca. Comment s'est passee ta journee?
ENOKI                            Bon, meme si je suis un peu inquiete.
DIANA                            Ah, et pourquoi?
ENOKI                            Eh bien, Aaron et Maple se dispute recemment.
DIANA                            Quelque chose est arrive?
ENOKI                            Et bien Aaron retient toujours ses emotions.
ENOKI                            Et Maple dit tout en face sans penser a nos sentiments.
DIANA                            C'est pas une bonne combinaison.
ENOKI                            Ca ce calme apres, mais ca me rend triste a chaque fois que ca arrive.
DIANA                            Je n'ai pas de freres et soeurs mais... C'est comme ca hein?
ENOKI                            Es tu aussi enfant unique? J'aurais aime avoir une soeur.
DIANA                            Moi un frere, moins de drames.
ENOKI                            Je vois, je vois.
DIANA                            Tiens-moi au courant, d'accord?
ENOKI                            D'accord.

DIANA                            He, Aaron! En quoi je peux t'aider?
AARON                            Tu as entendu parler du jeu de societe ce soir?
DIANA                            Oui! Je serai la. As-tu vu l'emission?
AARON                            J'ai parle a Maple, et elle semble connaitre ce Plonj.
AARON                            Elle ne parait pas derangee.
DIANA                            Oh, je suis contente d'entendre ca. On se voit ce soir?
AARON                            Bien sur!

SCOUT                            He! C'est moi, Scout.
DIANA                            He Scout! Quoi de neuf?
SCOUT                            Il semble que le Scout TV de ce mois-ci soit termine.
SCOUT                            Maintenant, je n'ai plus qu'a m'occuper de l'Expo Scout.
DIANA                            Tu en parles toujours, qu'est-ce que c'est exactement?
SCOUT                            C'est un endroit ou je montre mes inventions. D'habitude, je poste en ligne, mais la j'ai des amis a qui je peux montrer mes gadgets!
DIANA                            Ca a l'air amusant! Peux tu me faire un exemple?
SCOUT                            Ah, ah, ah. Tu vas d'avoir attendre l'Expo comme le reste.
DIANA                            D'accord... J'etais juste curieuse.
SCOUT                            ...Eh bien, j'ai cree cet appareil-
DIANA                            Mais tu viens de dire, que je devais attendre.
SCOUT                            Mais je- Et... hmm... J'avoue, j'ai de la misere a attendre
DIANA                            Heh, je le savais.

DIANA                            He, Vee! Comment ca va?
OLIVIER                          Bien, bien.
DIANA                            Tu viens  tu me damander pour organiser un jeu ici?
OLIVIER                          Non! Pas du tout... On le fais dehors.
OLIVIER                          Et si tout va bien, l'ile ne bruleras pas.
OLIVIER                          Comment vont tous le monde hors de l'ile?
DIANA                            Merveilleux! Mes parents aimeraient y passer un jour.
DIANA                            Bien que ma maison soit en desordre. Peux-tu me laisser la tienne?
OLIVIER                          Continue a rever, hahaha.
OLIVIER                          Je devrais inviter ma famille un jour.
DIANA                            Oh, ils aimeront l'ile.
DIANA                            J'espere que tout iras bien.
OLIVIER                          Esperons que oui. Haha.

ELEANOR                          Bonjour!
DIANA                            Bonjour ma cherie! What's up?
ELEANOR                          Oh, quelle est cette odeur? Etais-tu en train de petrir quelque chose?
DIANA                            Non, je crois que je dois nettoyer ma chambre...
DIANA                            Comment vas-tu? Quelque chose de nouveau?
ELEANOR                          Oh pas grand-chose, j'ai cousu une courtepointe..
DIANA                            Fantastique. Tu as utilise quoi comme materiel?
ELEANOR                          J'ai apporte tous les vetements de ma ville natale sur l'ile.
ELEANOR                          Ils sont tous bon pour la poubelle, mais j'ai honte de m'en debarrasser.
ELEANOR                          Ils ont toujours ete avec moi alors je vais en faire une courtepointe.
DIANA                            Aw, ca va etre magnifique.
DIANA                            As-tu dessine recemment?
ELEANOR                          Un peu! Il y a beaucoup de beaux paysages ici.
DIANA                            Je pourrais jouer de la guitare en voyageant l'ocean pour le reste de ma vie.
DIANA                            Well, quand je dis ocean, je veux dire  le lac.
DIANA                            Je crois que j'ai le coeur marin.
ELEANOR                          Ca semble etre une belle vie.
DIANA                            Arrrrrrrg, je vais etre une pirates!
DIANA                            Ne t'inquiete pas, je viendrais faire des visites tous le tempes
ELEANOR                          S'il te plait!

DIANA                            Salut! Tu es Guy, n'est-ce pas?
GUY                              C'est moi! Tu vis ici?
DIANA                            C'est humble mais c'est ma nouvelle maison. Tu aimes la tienne?
GUY                              Des mon plus jeune age, je revais d'avoir ma propre cuisine de taille industrielle a cote d'un lit escamotable.
DIANA                            C'est un reve tres specifique, mais je comprends.
GUY                              T'as meme pas de cuisine dans ta cabine?
DIANA                            J'ai un four et un mini frigo, haha.
DIANA                            J'apporte des produits importes donc je mange beaucoup de conserves
GUY                              C'est pas tres bon pour la sante tu sais?
DIANA                            Oui, eh bien, je vais penser a ca dans plusieurs annees.
DIANA                            Tout le monde devient gros et vieux un jour.
GUY                              Pas moi. Un jour, je serai plus vieux mais toujours en bonne sante et mince.
DIANA                            Nous verrons qui sera en meilleur sante quand nous atteindrons 50 ans.
GUY                              Avec plaisir.
DIANA                            Nous allons jouer a un jeu de societe ce soir. Tu viens?
GUY                              Non, je vais etre occupe avec ma cuisine toute la nuit.
DIANA                            Oh... D'accord, j'ai compris.
DIANA                            Tu me diras comment c'est.
GUY                              Bien sur!

OLIVIER                          O-Oh! Excusez-moi Madame. D'ou venez-vous?
GRAND-MERE CORINNE               Cette serre a fiere allure. As-t-elle ete bouge?
OLIVIER                          Oh, ils m'ont dit qu'ils l'avaient apporte de l'exterieur.
GRAND-MERE CORINNE               Tu vois jeune homme, cette serre etait la mienne.
GRAND-MERE CORINNE               Je pense qu'il ne sert a rien de le cacher, je suis un fantome.
OLIVIER                          Un fantome???
GRAND-MERE CORINNE               Il semble que je sois condamnee a hantee cette serre.
OLIVIER                          Mes excuses... Ca semble etre terrible...
GRAND-MERE CORINNE               Trouvez-vous terrible de passer une eternite ici?
OLIVIER                          A la reflexion... Je suppose que ce n'est pas si mal.
OLIVIER                          Mon sejour ici a ete agreable.
GRAND-MERE CORINNE               Je vois que tu aimes entretenir ces plantes, jeune homme.
GRAND-MERE CORINNE               Laissez-moi vous dire quelque chose avant de vous dire au revoir.
GRAND-MERE CORINNE               S'occuper des plantes semble  inutile.
GRAND-MERE CORINNE               Un bel avenir attend les gens patient.
GRAND-MERE CORINNE               Ce fut un plaisir de te rencontrer. Prends soin de toi!

OLIVIER                          O-Oh! Excusez-moi Madame. D'ou venez-vous?
GRAND-MERE CORINNE               Cette serre a fiere allure. As-t-elle ete bouge?
OLIVIER                          Oh, ils m'ont dit qu'ils l'avaient apporte de l'exterieur.
GRAND-MERE CORINNE               Tu vois jeune homme, cette serre etait la mienne.
GRAND-MERE CORINNE               Je pense qu'il ne sert a rien de le cacher, je suis un fantome.
OLIVIER                          Un fantome???
GRAND-MERE CORINNE               Il semble que je sois condamnee a hantee cette serre.
OLIVIER                          Mes excuses... Ca semble etre terrible...
GRAND-MERE CORINNE               Trouvez-vous terrible de passer une eternite ici?
OLIVIER                          A la reflexion... Je suppose que ce n'est pas si mal.
OLIVIER                          Mon sejour ici a ete agreable.
GRAND-MERE CORINNE               Je vois que tu aimes entretenir ces plantes, jeune homme.
GRAND-MERE CORINNE               Laissez-moi vous dire quelque chose avant de vous dire au revoir.
GRAND-MERE CORINNE               S'occuper des plantes semble  inutile.
GRAND-MERE CORINNE               Un bel avenir attend les gens patient.
GRAND-MERE CORINNE               Ce fut un plaisir de te rencontrer. Prends soin de toi!

DES INSTRUCTIONS:
?	Vous trouverez des choses autour de l'ile pour construire votre Trembloon. Si vous en obtenez 100, vous pouvez passer au chapitre suivant! Bonne chance!
?	Essayez d'attraper tous les lapins et de les jeter hors du jardin des que possible. Ramassez-les et jetez-les avec le bouton A. Bonne chance!
?	Essayez de trouver la gemme et evitez les chauves-souris. Si vous etes touche, la gemme se deplace vers un nouvel endroit. Tirez sur les chauves-souris pour gagner des points bonus. Bonne chance!
?	Utilisez le bouton A pour couper le bois. Assurez-vous de ne pas sortir de la ligne ou d'en manquer, sinon vous perdrez des points! Bonne chance!
?	Il y a de nouveaux villageois au nord-ouest! Il existe de nouvelles facons de gagner des Trembloons, mais vous devrez decouvrir comment vous-meme. Bonne chance!
?	Essayez d'obtenir la plus grande sequence de combinaisons de boutons d'affilee et vous pourrez invoquer un objet comme par magie! L et R sont les boutons. Bonne chance!
?	Pilotez le bateau pour eviter les rochers! Utilisez haut pour accelerer, gauche et droite pour diriger et bas pour arreter le bateau. Bonne chance!
?	Vous pouvez trouver la commande du client dans le coin superieur droit. N'oubliez pas d'appuyer sur R si vous avez besoin de jeter un coup d'oeil au livre de cuisine. Bonne chance!

LE BIZAAR D'CESAR                'NOUS AVONS SEULEMENT DEUX ARTICLES, DEAL WITH IT'

MAPLE                            Alors... Guy, uhg... Tu met de la tomate sur le Jambalaya?
GUY                              Comme Dieu le voulais.
MAPLE                            Comme Dieu le voulais?
MAPLE                            ...Tu te moque de moi?
GUY                              Tu fais aussi partie de ceux qui aiment leur roux brule?
MAPLE                            Definit 'brule'.
GUY                              Tellement brule qu'il perd ses couleurs et qu'on ne peut plus le gouter.
MAPLE                            Comment ca 'plus le gouter'. J'aime le gout!
GUY                              Oui, parce que tu l'enterre dans un tas d'epices au hasard.
MAPLE                            Mon choix d'epices n'est PAS aleatoire.
GUY                              j'ai plus rien a dire, si tu veux bien m'excuser, je vais balayer le sol
GUY                              de la cuisine pour faire un bon jambalaya.
MAPLE                            Les creoles sont mortelles en cusime.
GUY                              Pas autant que les acadiens, ma fille, tu sais quoi?
GUY                              Organisons un concours de gombos et laissons les autres juger, hein?
MAPLE                            Parfait. C'est de la tarte.

ENOKI                            Ooooooh... j'adore ta cuisine, elle est immense!
GUY                              Merci. Je peux meme rouler de mon lit pour prendre du pain de mais.
ENOKI                            J'aimerais ca aussi, hehe.
GUY                              Au fait, euh. Cette Maple... Est-ce que son gombo est meilleur ou le mien?
ENOKI                            Es-tu en competition avec elle? Si oui, je veux pas choisir.
ENOKI                            Je veux pas me retourner contre toi maintenant que tu as demenage ici.
ENOKI                            Mais tu devrais savoir que Maple et moi somme meilleures amies.
GUY                              Peut-etre que je peux te cuisiner un gombo qui te fera reconsiderer.
ENOKI                             Ca vas etre complique. Je n'aime pas vraiment manger /tant/ que ca.
GUY                              Mais... Ah, anyway. Prends soin de toi, cherie.

AARON                            Ca sent bon ici!
GUY                              Oui, c'est comme ca que ca doit etre.
AARON                            He, j'ai entendu dire que tu etais venu chercher des clients?
GUY                              C'est vrai.
AARON                            Well, euh... Comme tu peux le voir, on est pas beaucoup ici.
AARON                            Bien que j'essaie de faire de l'ile un beau chez-soi.
GUY                              Ou veux-tu en venir?
AARON                            J'espere juste que vous savez que nous sommes pas assez nombreux pour avoir notre propre monnaie et c'est pas tout qui traine du cash.
GUY                              Je facture que 5 dollars, c'est abordable et j'attends des clients.
AARON                            You knoe what? Combien coute cette cabine? 10 ou 20 mille dollars?
AARON                            Je sais pas faire de maths, j'ai jamais obtenu mon diplome d'etudes secondaires.
AARON                            Elle n'est pas la, mais Enoki peut faire des calculs complexes.
AARON                            Et si tu donnais des repas gratuits pour le reste de l'annee?
AARON                            Et ca payeras le loyer. C'est bon?
GUY                              Je vais y reflechir.

OLIVIER                          O-Oh! Excusez-moi Madame. D'ou venez-vous?
GRAND-MERE CORINNE               Cette serre a fiere allure. As-t-elle ete bouge?
OLIVIER                          Oh, ils m'ont dit qu'ils l'avaient apporte de l'exterieur.
GRAND-MERE CORINNE               Tu vois jeune homme, cette serre etait la mienne.
GRAND-MERE CORINNE               Je pense qu'il ne sert a rien de le cacher, je suis un fantome.
OLIVIER                          Un fantome???
GRAND-MERE CORINNE               Il semble que je sois condamnee a hantee cette serre.
OLIVIER                          Mes excuses... Ca semble etre terrible...
GRAND-MERE CORINNE               Trouvez-vous terrible de passer une eternite ici?
OLIVIER                          A la reflexion... Je suppose que ce n'est pas si mal.
OLIVIER                          Mon sejour ici a ete agreable.
GRAND-MERE CORINNE               Je vois que tu aimes entretenir ces plantes, jeune homme.
GRAND-MERE CORINNE               Laissez-moi vous dire quelque chose avant de vous dire au revoir.
GRAND-MERE CORINNE               S'occuper des plantes semble  inutile.
GRAND-MERE CORINNE               Un bel avenir attend les gens patient.
GRAND-MERE CORINNE               Ce fut un plaisir de te rencontrer. Prends soin de toi!

OLIVIER                          Bonjour!
GUY                              Oui. J'suppose que tu es le jardinier?
GUY                              Cultive-tu du celeri, de l'oignon et des poivrons?
OLIVIER                          Bien sur!
GUY                              Tu sais? Tu peux m'apporter de la marchandise fraiche.
GUY                              En retour, je te cuisinerais du gombo gratuitement.
OLIVIER                          Et ma femme?
GUY                              C'est celle avec la tenue ou les cheveux de Wendy?
OLIVIER                          ...C'est celle qui a les cheveux bruns.
GUY                              Je vois, merci Dave.
OLIVIER                          ...Olivier. Olivier Landry.
OLIVIER                          Ton nom est Guy non?
GUY                              Correct.
OLIVIER                          'Guy Pizza'?
GUY                              C'etait une blague, mais ne le dis a personne. Compris?
OLIVIER                          Compris.

ELEANOR                          Bonjour! Comment allez-vous?
GUY                              C'est bon, et comment vas-tu?
ELEANOR                          Cet endroit me donne vraiment faim, et ca sent bon!
GUY                              Vraiment?
ELEANOR                          J'aime la patisserie plus que cuisiner, mais cette cuisine est geniale!
GUY                              Qu'est-ce que tu aimes faire au four?
ELEANOR                          Ma preferee est la tarte au citron vert, meme si je dois faire beaucoup de pacanes pralinees. Aimes-tu ca?
GUY                              Si j'aime le praline?
GUY                              SI J'AIME LA PRALINE?
GUY                              C'est delicieux.
GUY                              Tu m'apporte des pralines et je t'offre des repas gratuits, d'accord?
ELEANOR                          Affaire conclue!

DIANA                            Salut! Tu es Guy Pizza si je me souviens bien?
GUY                              Guy Pizza, the one and only.
DIANA                            Je peux comprendre pourquoi, haha. Tu es italien?
GUY                              Non, je viens de Donaldsonville. Nouveau nom, nouvelle vie.
DIANA                            Et tu as choisit 'pizza'?
GUY                              Les gens m'appellent "pizza guy" depuis des annees.
GUY                              Mon nom est Guy en plus et ca rend les gens affames.
DIANA                            Bien sur, tous le monde aime la pizza. En fais tu souvent?
GUY                              Pas vraiment.
DIANA                            Tu peux toujours change de nom.
GUY                              As-tu des suggestions?
DIANA                            Guy... le Mysterieux. Les gens aiment l'enigmatique
GUY                              Je suis pas magician.
DIANA                            Tu n'es pas une pizza non plus.
GUY                              Touche.
GUY                              Je vais me rappeler d ca.

AARON                            On dirait qu'il n'y a personne a la maison.
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

SCOUT                            Salut tout le monde! Scout est la! C'est le moment!
                                 Scout TV est une chose reguliere! Comme vous pouvez le voir, maintenant je me sens comme un vrai journaliste!
                                 Nous sommes tous sur l'ile depuis trois mois. Je peux pas dire si c'est plus comme un jour ou un million d'annees!
                                 Bon. Cela fait un moment depuis la derniere fois, mais il semble que deux autres personnes se soient jointes a nous!
                                 Nous avons d'abord Cesar de la Cruz, un invite special de notre reine Enoki.
                                 Apparemment, il etait un celebre avocat a la recherche d'un nouveau depart.
                                 Nous avons aussi un nouveau gars qui emmenage. Il s'appelle Guy et il est cuisinier!
                                 J'ai hate de voir ca nourriture! Sont jambalaya est exceptionnellement repute!
                                 De plus, nousnous rapprochons de la Scout Expo, et ce n'est qu'une question de temps avant qu'elle soit prete!
                                 J'ai aussi commande un tas de numeros de Time Raiders parce que je sais que certains insulaires se sont mis a...

. . .
RUFUS                            Moi, euh- hmm.. oui, bonsoir, voisins de l'ile. Je suis Rufus Thibodeaux, et si vous ne me connaissez pas, vous allez le decouvir.
                                  J'interromps cette transmission pour donner un ultimatum. Soit ils me donnent l'ile, soit je vais-!
                                  . . . .

                                  -Et c'est tous les amis! A la prochaine!
ENOKI                            Aw, j'ai rate l'emission de Scout... Je l'attendais avec impatience...
MAPLE                            He, n'etait-ce pas le neveu de cet abruti de Del? Il s'est arrete sur l'ile il y a quelques mois, je crois.
AARON                            Quelle etrange transmission.
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
ENOKI                            He, Aaron?
AARON                            *Baille* Oui?
ENOKI                            Etes-tu heureux?
AARON                            Bien sur que je le suis, Noke.
ENOKI                            Je veux dire, es tu vraiment heureux? Je m'inquiete pour toi.
AARON                            Je suppose que je suis un peu melancolique a ce sujet, c'est tout.
ENOKI                            Qu'est-ce que tu veux dire?
AARON                            Tu sais. Maple avait raison, nous ne pouvons etre ici que grace a l'argent que tu as gagnee.
AARON                            Nous avons tout donne pour cet endroit et si quelque chose tourne mal, nous aurons absolument rien.
ENOKI                            Tu me connais deja moi et ma chance, en plus je t'ai a mes cotes c'est tout ce dont j'ai besoin.
AARON                            Tu penseras tu comme ca lorsque tu seras affamee. Tu ne sais pas ce que c'est que d'avoir faim.
ENOKI                            Je veux pas y penser... Si je le fais, je ne pourrai pas dormir.
ENOKI                            Pouvons-nous juste etre heureux? Nous en reparlerons une autre fois.
AARON                            Je suppose que oui. Bonne nuit, Noc-Noc.
ENOKI                            Bonne nuit, Aaron.
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

CESAR                            Ah! Heureux de vous rencontrer! Vous devez etre l'un des habitants. Vous pouvez m'appeler Cesar.
                                 Croyez-le ou non, j'etais avocat, mais je n'etait pas vraiment un bon avocat.

                                 Je n'avais pas de diplome, mais je gagnais quand meme chaque fosi.
                                 Pourquoi je te dis ca alors que nous ne nous sommes jamais rencontres auparavant?
                                 ...
                                 ...
                                 C'est mieux si on se connait tous un peu. Non?
                                 J'aime m'occuper et je realise mon reve d'etre un commercant dans un endroit calme.
                                 Si vous voyez des clients etrangers qui sont en colere contre moi, faites-le moi savoir pour que je puisse... euh. Me chachez. Merci!
                                 Quoi qu'il en soit, ai-je un article qui attire votre attention?

When you walk into the store (Enoki)

                                 Enoki Ramirez! Er... Tremblay nowis it? Anyway, thank you so much for letting me come here.
                                 I promise I won't cause any      trouble, but those last clients  of mine...

                                 Look, it's not MY fault that I   was able to pretend to be a      lawyer really well, you know?

                                 I know you understand. Just let  me know if they arrive so I can, you know, er.. hide.
                                 It's been a childhood dream of   mine to be a shopkeep in some    little village, and I don't have a lot to sell,
                                 But I'll do my best! Anyway, how can I help you today?

. . . .
                                 Enoki Ramirez! Euh... Maintenant Tremblay, non? Merci beaucoup de m'avoir permis de venir ici.
                                 Je promets que je ne causerait aucun probleme ici, bien que mes derniers clients...

                                 Ecoute, ce n'etait pas MA faute si j'etais si doue pour faire semblant d'etre un avocat de haut niveau, tu sais?

                                 Je sais que tu me comprends. Faites-moi savoir s'ils viennent me chercher pour que je puisse me cacher a temps. Bien?
                                 Mon reve depuis que je suis enfant est d'etre commercant dans une petite ville, meme si je n'ai pas grand-chose a vendre.
                                 Maintenant que j'en ai l'opportunite, je ferai de mon mieux! Comment puis-je vous aider aujourd'hui?
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

RUFUS                            Bonjour a tous. Il semble que mon avertissement precedent n'etait pas suffisant et personne n'a montre le moindre 
RUFUS                            soupcon de peur au cours du mois dernier. vous avez fait une grave erreur, car je prevois prendre l'ile par la force si necessaire.
MAPLE                            ...Ugggh, tais-toi, Rufus, j'essaie de dormir.
RUFUS                            J'ai developpe un-
ENOKI                            Je ne me souviens pas d'avoir allume la tele ce matin, tu l'as allume, Maple?
MAPLE                            ...
AARON                            J'ai peut-etre heurte quelque chose par accident. Je l'eteins?
MAPLE                            ...mmmrff... TV... off... Samedi...
RUFUS                            Dans moins de trente secondes, je lacherai mon-

AARON                            D'accord, c'est fini.
ENOKI                            C'etais quoi?
AARON                            Aucune idee, Noke.
MAPLE                            ...
ENOKI                            He, c'est quoi ce bruit?
AARON                            Je n'aime pas ce son.. Maple, tu devrais peut-etre te lever.
MAPLE                            ...Grr, je vais tuer cet alligator...
ENOKI                            Mais quoi- oh non...
AARON                            Enoki, toi et Maple courez au bunker de Scout, je vais vers l'ouest pour voir si les autres vont bien.
MAPLE                            Excusez-moi, je peux m'occuper de mon-
AARON                            Tu vas aller au bunker, en plus tu pourras still y dormir.
MAPLE                            He, pas besoin d'etre aussi passif-agressif avec moi.
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

MAPLE                            Dis-moi la verite, C'est toi qui a construit cet endroit?
SCOUT                            Oh que non! Bien que j'aurais aime le faire.
SCOUT                            MAPLE, ATTENTION!
MAPLE                            ... Scout, tu vas bien?
RUFUS                            Aie. Meme si je me suis un peu cogne le dos. Je pense que ca ira.
MAPLE                            Qu'est-ce que toute cette gasoline fait ici?
SCOUT                            Pour notre bien, vous feriez mieux d'etre prudent avec vos pouvoirs.

MAPLE                            ...
MAPLE                            Quoi... Quesque je regarde en ce moment?
RUFUS                            Ichabod Williams et Maple Tremblay, Quelle surprise! Je suis content de vous autres voir ici.
RUFUS                            Enfin, nous avons tous pu nous rencontrer.
SCOUT                            RUFUS Qu-, QU'EST-CE QUE TU FAIS?
MAPLE                            LAISSEZ-MOI TRANQUILLE, ENFANT!
RUFUS                            Tu ferais mieux de mettre un bracelet anti-magie sur toi pour eviter d'en avoir... Des etincelles d'inspiration
RUFUS                            Bon, maintenant que nous avons tous les Tremblay reunis au meme endroit... nous pouvons commencer!
RUFUS                            Tout d'abord, faisons une breve introduction. Je suis Monsieur Rufus Thibodeaux, et aujourd'hui je serai votre professeur.
RUFUS                            Faites attention. Personne ne semble m'ecouter, alors nous ferons un quiz a la fin de la seance.
RUFUS                            Lecon numero un. Repetez apres moi, 'Rufus n'est pas petit. Il n'a que de petits os.
MAPLE                            .....Tu plaisante?
RUFUS                            Ca ressemble pas a la phrase que tu as a dire maintenant, n'est-ce pas, Maple?
RUFUS                            Il semble que tout le monde echoue cette lecon. Alors passons au suivant... Parlons de la fleur d'Apres. Une entreprise m'a engage pour           
RUFUS                            l'etudier. Tout comme Ichabod... ou 'Scout', cette fleur est native et contient
RUFUS                            des "proprietes metaphysiques"  cool non? Malgre mes instructions. Un jour, je me suis ennuye et j'ai decide de prendre quelques                                             
RUFUS                            bouchees. Et savez-vous ce qui s'est passe ensuite?
RUFUS                            Je me suis retrouve a voyager a travers le multivers. J'ai explore toutes sortes de mondes differents, certains similaires a celui-ci et    
RUFUS                            d'autres completement eloignes de cette realite. Mais savez-vous ce que j'ai decouvert dans presque chacun d'entre eux?
RUFUS                            Il y avait une tendance etrange de femmes attirantes  combattant le mal de ces mondes.
RUFUS                            Avec des hommes flamboyants qui servait de cible a toutes les blagues ou ont etais  des mechants incompetents.
RUFUS                            A la fin, ils ont tous ete remplaces par des mechantes plus competentes et incompris qui etais mauvaise parce que un homme les avaient      
RUFUS                            maltraitee. Pouvez-vous deviner ce que je pensais a ce moment-la?
MAPLE                            Calme-toi-
MAPLE                            Es-tu vraiment en train de me dire que tu es devenu mechant simplement parce qu'une fleur t'a dit
MAPLE                            tu es le 'mechant'?
RUFUS                            Je crois qu'avec une frappe preventive, je peux garder intacte mon image et mon autonomie. Oui.
RUFUS                            De mon point de vue et apres avoir etudie ses attributs, Maple ressemble au "personnage principal" et c'etait mon meilleur plan.
ENOKI                            Monsieur Rufus, puis-je aller aux toilettes?
RUFUS                            Vous pouvez y aller apres la lecon. J'ai presque fini.
RUFUS                            Voyons, ou etais-je...?
AARON                            Rufus, nous devons parler.
AARON                            D'abord. Je suis surpris que tu savais pas que ma femme est magicienne. Elle est bonne pour s'echapper a travers des espaces restreints.
AARON                            Et deuxiemement. Je me fiche de ce que tu as vu avec cette fleur, tu as effraye tous mes amis.
AARON                            C'est totalement inacceptable. Tu ne peux pas kidnapper des gens et les garder en otage.
AARON                            Lache-nous et laisse-nous tranquille, c'est bon? Comprends-tu?
RUFUS                            Attend une minute, Aaron.
RUFUS                            Il y a quelque chose que tu dois savoir. Les portes de cette piece sont hermetiquement fermees.
RUFUS                            Si une bombe explosait a l'exterieur, nous le serions pas. Mais les portes s'ouvriront...
RUFUS                            si quelqu'un goute la fleur. Alors je vous mets au defi. Si vous parvenez a me battre, je laisserai votre ile en paix.
RUFUS                            Si je gagne, je deviendrai le nouveau roi. Mais vous devez prendre la fleur pour sortir.
RUFUS                            Une fois que l'un d'entre vous aura vu tout ce que j'ai vu, vous cesserez de me prendre pour un imbecile.
RUFUS                            Nous verrons ce qui se passera...
RUFUS                            Bien, bien, bien...
RUFUS                            HA! On dirait que je gagne! C'est le moment d'utiliser la fleur d'Apres!
RUFUS                            Alors... qui va la gouter? Aaron? Que pense?
MAPLE                            Tu sais quoi? Meme pas dans tes reves, petit gars.
RUFUS                            Qui appelles-tu petit gars?
MAPLE                            Meme tes petites jambes robotiques son sur la pointe de leurs pieds.
MAPLE                            Je sais pas pourquoi tu es obsede par l'idee que le monde est comme ton reve de creer par les fleurs.
MAPLE                            Mais la vie est dure, tu sais? Je me fiche de ce que tu as vu dans tes reves, tu ne peux pas venir nous deranger sur notre propre ile. 
MAPLE                            On savait meme pas qui tu etais. je vais te menacer comme je menace tout le monde. Si tu continu a nous menacer je vais-
RUFUS                            Je-je sais, je sais, tu l'as deja dit, tu vas me griller le visage.
RUFUS                            Bien que, euh, fais attention au feu. Il y a beaucoup d'objets inflammables ici.
MAPLE                            FAIS ATTENTION? Tu dis de faire attention apres nous avoir KIDNAPPES? Finalement,ton visage va bruler!
CESAR                            He, Maple?
MAPLE                            NON CAESAR, JE DOIS PRENDRE SOIN DE CE PETIT MEGALOMANE!
RUFUS                            N-non vraiment, tu as, euh, euh... Mon Dieu...
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


GUY                              Je me sent bien ici.
DIANA                            Si la c'etait pas si chere, je le ferais tout le temps.
GUY                              Penses-tu que des touristes viendront sur l'ile?
DIANA                            Tu devrais te detendre un peu avec ton restaurant.
DIANA                            Tu devrais prendre une pause et te detendre de temps en temps, non?
GUY                              J'suppose que je devrais. Mais la cuisine est comme mon bebe, je ne peux pas m'en empecher.
DIANA                            Et si elle explosait soudainement un jour?
GUY                              ...
DIANA                            ...
GUY                              ...Mais.

RUFUS                            Mais quoi...
RUFUS                            ...
MAPLE                            Je... je-je...
AARON                            Maple, je-
MAPLE                            ... je-je suis...
ENOKI                            Maple, reviens!
MAPLE                            ...
AARON                            Maple, leve-toi.
MAPLE                            ...
AARON                            Maple, nous devons parler. Maintenant.
ENOKI                            Maple, tu es-
AARON                            Maria, je t'aime, mais Maple et moi devons parler.
ENOKI                            Maria...
ENOKI                            D-D'accord, je vais voir comment vont les autres.
AARON                            Maple. Nous devrions avoir  cette conversation depuis longtemps, et je ne peux plus attendre.
AARON                            Je pense que tu sais de quoi il s'agit.
MAPLE                            Je-je n'ai pas envie de parler en ce moment.
AARON                            Je veux m'excuser.
AARON                            Je me suis plaint de toi aux autres.
AARON                            Bien qu'au final tu aies fait beaucoup de choses qui me rendent fier d'etre ton grand frere.
AARON                            Tu as cette colere qui est en toi tout le temps, une colere que tu projettes vers tout ce que tu vois comme mauvais dans ce monde.
AARON                            La colere n'est pas une mauvaise chose, mais je vois que tous ce qui te met en colere c'est des choses que tu vois aussi en toi.
AARON                            Merci pour tout, j'apprecie vraiment que tu me defendes.
MAPLE                            Tais-toi.
AARON                            Je ne vais pas me taire.
AARON                            Prends ton temps pour te calmer, mais tu devras apprendre a controler ta colere. Ou je ne pourrai plus te soutenir.
MAPLE                            ...Oui.
AARON                            Je suis content que tu comprennes. Rufus, je pense que nous avons aussi quelque chose a nous dire.
ENOKI                            A-Aar.. AARON, ATTENDS!
AARON                            Nous devons ouvrir ces portes.
RUFUS                            He, je suis sur que je peux trouver un moyen de desactiver le verrou. Je pense que tu n'as pas a-
AARON                            Je vais le faire.
                                 N-Non... je ne peux pas te perdre...
                                 A-Aaron? Pourquoi me regardes-tu ainsi?
                                 Dis quelque chose... tu me fais peur...
AARON                            J'ai paye l'ile en especes. Nous devrions en avoir assez pour louer une maison en Louisiane.
AARON                            Un acadien ne trouvera jamais une meilleure maison en dehors de la Louisiane de toute facon, oui?
AARON                            Je pense que j'ai assez d'argent pour payer a tout le monde quelques mois de loyer jusqu'a ce qu'ils puissent reprendre une vie normale.
AARON                            Je veux dire que ce fut un honneur pour moi d'etre votre roi pendant cette periode. Merci a tous d'etre la.
OLIVIER                          Nous tenons egalement a vous remerciez. Je sais pas ce que moi et Eleanor allons faire, mais... On trouvera quelque chose.
OLIVIER                          Nous sommes venus ici parce que nous n'avions pas de ressources. Donc vous rencontrez a ete une benediction.
CESAR                            Et il ne fait aucun doute que Enoki m'a sauve la mise.
RUFUS                            Je... Je peux aider si quelqu'un a besoin de moi ou a besoin d'un logement. Je suis vraiment desole pour votre ile...
RUFUS                            Je n'ai jamais vraiment voulu causer autant de problemes, j'etais juste ici pour jouer un peu l'antagoniste, je...
RUFUS                            He, j'ai des couvertures et des trucs si tu as besoin de passer la nuit.
AARON                            ...Merci, Rufus.
AARON                            Nous aurons tous besoin de temps pour assimiler ce qui s'est passe. J'ai cependant pas vu le bateau de Diana sur les images de l'ile.
AARON                            Tout le monde semble okay. Et a la fin, c'est la chose la plus importante de toutes.
AARON                            Je vous aime tous.

SCOUT                            Maple, comment ca va?
MAPLE                            ...
MAPLE                            ... N'ose pas t'inquieter pour moi. C'est clair?
SCOUT                            Oui, bien sur, c'est juste... je suis desole pour-
MAPLE                            Desole pour quoi?
SCOUT                            Laisse-moi finir.
MAPLE                            Bon. Continue.
SCOUT                            Desole d'etre audacieux, mais s'il te plait, arrete de te blamer autant. Je suis de ton cote, tu sais?
MAPLE                            Quoi, tu vas m'inviter a sortir ou quoi?
SCOUT                            Non, je-je... eh well, non, je suis pas... Ecoute, je veux juste pas te perdre.
SCOUT                            Je suis pas en colere contre toi, et... he, je ne voudrais pas gacher notre amitie non plus.
SCOUT                            juste parce que tu es en colere, d'accord? Tu es plus important que l'ile. Et...
SCOUT                            Je veux que tu me promettes que tu n'iras nulle part ou faire quelque chose de stupide a cause de ca je t'en prie!
MAPLE                            ...
MAPLE                            ...Je ne ferais, ne t'inquiete pas pour moi.

...

ENOKI                            He, Maple! Tu es de retour?
MAPLE                            Oui. L'entretien s'est bien passe. Etre dans l'armee ressemble a une corvee, mais les avantages sont enormes.
AARON                            Je sais que tu t'en sortiras tres bien, Maple.
MAPLE                            TU es serieuse?
AARON                            Je parie que tu seras la seule elfe du peloton. Et cela jouera en ta faveur.
MAPLE                            Oui, je pense que oui. J'en ai parle a Scout. Il dit qu'il est heureux mais je vais lui manquer.
ENOKI                            Tu nous manqueras aussi.
ENOKI                            Well, Aaron et moi avons aussi des nouvelles pour toi.
MAPLE                            Wow, quelles nouvelles?
ENOKI                            Il parait que bientot... Euh... Que bientot il y aura un nouveau Tremblay avec nous.
MAPLE                            Attendez, ne me dit pas-?
ENOKI                            Ah!
MAPLE                            Est-tu... ENCEINTE?
AARON                            Oh que oui, miss
MAPLE                            C'est pas possible, je suis... je vais etre tante. Quel genre de personne sortira d'un melange comme Aaron et Enoki?
ENOKI                            2000 a ete une annee incroyable, et je suis sur que 2001 sera encore meilleure!
AARON                            Quelle que soit l'aventure qui nous attend, je suis contente que vous soyez avec moi.
MAPLE                            Bonne annee 2001, les gars!
ENOKI                            Bonne annee 2001!
"""

final = []

for line in data.split('\n'):
    cache = line
    start = 0

    while (len(cache) > start):
        back = 0
        while start + 33 - back < len(cache):
            if cache[start + 33 - back] == ' ':
                cache[min([start - back, len(cache)])]
                cache = cache[0:start + 33 - back] + ''.join([' ' for t in range(back)]) + cache[start + 33 - back:].strip()
                break
            back += 1
        start += 33

    final_bit = cache[start:].strip()
    while "  " in final_bit:
        final_bit = final_bit.replace("  ", " ")

    cache = cache[0:start] + final_bit
    
    final.append(cache)

with open('honyaku_proc.txt', 'w') as f:
    f.write('\n'.join(final))