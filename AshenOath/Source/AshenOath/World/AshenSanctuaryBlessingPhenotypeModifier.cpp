// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "World/AshenSanctuaryBlessingPhenotypeModifier.h"

UAshenSanctuaryBlessingPhenotypeModifier::UAshenSanctuaryBlessingPhenotypeModifier()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenSanctuaryBlessingPhenotypeModifier::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	BlessingPotency = FMath::Clamp(NewState.Resolve * 2.0f, 0.2f, 3.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenSanctuaryBlessingPhenotypeModifier: Sanctuary Blessing potency updated to %.2f"), BlessingPotency);
}
