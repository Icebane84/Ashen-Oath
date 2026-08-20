// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenStanceFinisherAnimationAdapter.h"

UAshenStanceFinisherAnimationAdapter::UAshenStanceFinisherAnimationAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenStanceFinisherAnimationAdapter::BeginPlay() { Super::BeginPlay(); }

bool UAshenStanceFinisherAnimationAdapter::PlayStanceFinisherMontage(FName StanceName)
{
	UE_LOG(LogTemp, Log, TEXT("UAshenStanceFinisherAnimationAdapter: Stance finisher montage played for '%s'"), *StanceName.ToString());
	return true;
}
