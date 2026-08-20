// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenPartySyncFinisherSubsystem.h"
#include "AshenBestiaryFinisherDialogueAdapter.generated.h"

/**
 * UAshenBestiaryFinisherDialogueAdapter
 * Specific tactical companion voice callouts for all 18 enemy types.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBestiaryFinisherDialogueAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenBestiaryFinisherDialogueAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerBestiaryCallout(EAshenPartyFinisherType FinisherType, FName CompanionID);
};
