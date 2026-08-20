// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AI/AshenTraumaEnemyMatrixTypes.h"
#include "AshenTraumaDialogueAdapter.generated.h"

/**
 * UAshenTraumaDialogueAdapter
 * Manages companion dialogue barks reacting to Kaelen's Glass Shield isolation shoves and Serafina's blue fingernails.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTraumaDialogueAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenTraumaDialogueAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerIsolationShoveBark(FName ShovedHero);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerEmpathicBurnoutReactionBark();
};
