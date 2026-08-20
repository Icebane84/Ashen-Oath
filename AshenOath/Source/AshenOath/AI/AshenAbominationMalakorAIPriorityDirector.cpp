// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 768: Ashen Abomination Malakor AI Priority Director

#include "AshenAbominationMalakorAIPriorityDirector.h"

FName UAshenAbominationMalakorAIPriorityDirector::SelectMalakorNextAttack(float KaelenPosturePercent, bool bIsAegisGuarding)
{
	FName AttackTag = FName(TEXT("Attack.VoidSmash"));
	float Aggression = 80.0f;

	if (bIsAegisGuarding && KaelenPosturePercent < 40.0f)
	{
		AttackTag = FName(TEXT("Attack.HeavyShieldBreaker"));
		Aggression = 100.0f;
	}

	OnAttackSelected.Broadcast(AttackTag, Aggression);

	UE_LOG(LogTemp, Warning, TEXT("UAshenAbominationMalakorAIPriorityDirector: MALAKOR ATTACK SELECTED -> Attack: '%s' | Aggression: %.1f."),
		*AttackTag.ToString(), Aggression);

	return AttackTag;
}
