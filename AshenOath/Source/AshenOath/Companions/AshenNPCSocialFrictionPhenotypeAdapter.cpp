// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#include "Companions/AshenNPCSocialFrictionPhenotypeAdapter.h"

UAshenNPCSocialFrictionPhenotypeAdapter::UAshenNPCSocialFrictionPhenotypeAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UAshenNPCSocialFrictionPhenotypeAdapter::OnSoulStateInvalidated(const FSoulStateVector& NewState)
{
	SocialFrictionScalar = FMath::Clamp(NewState.Corruption * 0.85f, 0.0f, 1.0f);
	UE_LOG(LogTemp, Log, TEXT("UAshenNPCSocialFrictionPhenotypeAdapter: NPC social friction scalar updated to %.2f"), SocialFrictionScalar);
}
