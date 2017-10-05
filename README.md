Programming Tournament
Simulate a tournament where monsters fight against each other, inside a text-based console application. 

Most monster attributes are randomly generated. MonsterType is read from a text file and includings name and attack style. Each monster then gets paired up with another monster and they fight. CalculateDamageToGive() will determine how much HP to remove off the enemy monster and first one to lose all their HP is eliminated. That is then repeated until one monster remains which is the winner. 

50 Monsters
5 Weapons

CONSTS
enum AttackStyle: Swing, Stab, Slash….
enum MonsterType: Orc, Goblin....
enum WeaponType: Sword, Dagger….

TOURNAMENT CLASS
Vars: MonsterManager
Funcs: SetupTournament(), PlayRound(), FinishTournament()

MONSTER CLASS
Vars: MONSTERTYPE, HP, Attack Accuracy, Defence, WEAPON.
Funcs: RecieveDamage(), CalculateDamageToGive(), Die().

MONSTERTYPE STRUCT
Vars: MonsterType, AttackStyle

MONSTERMANAGER CLASS
Vars: Monsters

WEAPONTYPE STRUCT
Vars: Damage, Name.

