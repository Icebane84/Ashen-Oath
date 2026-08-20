// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 671: Ashen Oathbringer Greatsword Actor

#include "AshenOathbringerGreatswordActor.h"

AAshenOathbringerGreatswordActor::AAshenOathbringerGreatswordActor()
{
	PrimaryActorTick.bCanEverTick = false;
	bIsResonanceTuned = true;
	BaseWeaponDamage = 150.0f;
}

void AAshenOathbringerGreatswordActor::ReflectAegisEnergy(float IncomingDamage, FName ElementType)
{
	const float ReflectedDamage = IncomingDamage * 1.5f;
	OnAegisReflected.Broadcast(ReflectedDamage, ElementType);

	UE_LOG(LogTemp, Warning, TEXT("AAshenOathbringerGreatswordActor: AEGIS REFLECTION TRIGGERED -> Reflected: %.1f [%s] damage back to attacker."),
		ReflectedDamage, *ElementType.ToString());
}
