// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenLivingCodexTypes.h"
#include "AshenNarrativeAmbientDirectorComponent.generated.h"

/**
 * UAshenNarrativeAmbientDirectorComponent
 * AI Director managing ambient conversation pacing, companion idle chatter cooldowns, and lore landmark callouts.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenNarrativeAmbientDirectorComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenNarrativeAmbientDirectorComponent();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Narrative")
	float MinChatterCooldown = 30.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	bool ShouldTriggerAmbientBark(float TimeSinceLastBark, bool bInCombat) const;
};
