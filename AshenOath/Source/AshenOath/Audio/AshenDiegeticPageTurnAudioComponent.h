// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticPageTurnAudioComponent.generated.h"

/**
 * UAshenDiegeticPageTurnAudioComponent
 * Audio component modulating crisp page flips, heavy paper crinkles, and charcoal scrawl SFX.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticPageTurnAudioComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticPageTurnAudioComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Audio")
	float PageTurnVolume = 0.8f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void TriggerPageTurnSFX();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void TriggerCharcoalScrawlSFX();
};
