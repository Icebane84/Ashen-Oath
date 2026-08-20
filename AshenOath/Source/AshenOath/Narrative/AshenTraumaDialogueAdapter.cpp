// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Narrative/AshenTraumaDialogueAdapter.h"

UAshenTraumaDialogueAdapter::UAshenTraumaDialogueAdapter()
{
	PrimaryComponentTick.bCanEverTick = false;
}
void UAshenTraumaDialogueAdapter::BeginPlay() { Super::BeginPlay(); }

void UAshenTraumaDialogueAdapter::TriggerIsolationShoveBark(FName ShovedHero)
{
	if (ShovedHero == FName(TEXT("Hero.Garrett")))
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenTraumaDialogueAdapter: Garrett: \"Dammit, Kaelen! Stop pushing me out of the pocket! We take the blow together!\""));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("UAshenTraumaDialogueAdapter: Serafina: \"Kaelen, don't shut us out!\""));
	}
}

void UAshenTraumaDialogueAdapter::TriggerEmpathicBurnoutReactionBark()
{
	UE_LOG(LogTemp, Warning, TEXT("UAshenTraumaDialogueAdapter: Garrett: \"Serafina... your hands. Your nails are turning blue. Drop back!\""));
}
