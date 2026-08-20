// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 682: Ashen Crossguard Throw Positional Ability

#include "AshenCrossguardThrowPositionalAbility.h"

void UAshenCrossguardThrowPositionalAbility::ExecuteCrossguardThrow(AActor* TargetEnemy, FVector ThrowDirection)
{
	if (!TargetEnemy) return;

	const FVector TargetLocation = TargetEnemy->GetActorLocation() + (ThrowDirection.GetSafeNormal() * 400.0f);
	OnThrowExecuted.Broadcast(TargetEnemy, TargetLocation);

	UE_LOG(LogTemp, Warning, TEXT("UAshenCrossguardThrowPositionalAbility: CROSSGUARD POSITIONAL THROW EXECUTED -> Enemy '%s' thrown to (%s)."),
		*TargetEnemy->GetName(), *TargetLocation.ToString());
}
