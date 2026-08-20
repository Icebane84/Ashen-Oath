// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "World/AshenMemoryFragmentActor.h"

AAshenMemoryFragmentActor::AAshenMemoryFragmentActor()
{
	PrimaryActorTick.bCanEverTick = false;
	FragmentID = TEXT("Fragment_001");
	ImprintWeight = 0.5f;
	bRequiresLorekeeper = false;
	bHasBeenConsumed = false;
}
void AAshenMemoryFragmentActor::BeginPlay() { Super::BeginPlay(); }

bool AAshenMemoryFragmentActor::InteractWithFragment(AActor* InteractingPlayer, float CompanionTrust)
{
	if (bHasBeenConsumed) return false;
	if (bRequiresLorekeeper && CompanionTrust < 0.60f)
	{
		UE_LOG(LogTemp, Warning, TEXT("AAshenMemoryFragmentActor: Cannot unseal fragment '%s' — Requires Lorekeeper (Trust %.2f < 0.60)."),
			*FragmentID.ToString(), CompanionTrust);
		return false;
	}

	bHasBeenConsumed = true;
	UE_LOG(LogTemp, Log, TEXT("AAshenMemoryFragmentActor: Discovered psychic memory fragment '%s' (Weight: %.2f)!"),
		*FragmentID.ToString(), ImprintWeight);
	return true;
}
