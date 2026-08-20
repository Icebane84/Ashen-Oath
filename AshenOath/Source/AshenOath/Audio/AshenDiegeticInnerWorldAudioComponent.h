// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticInnerWorldAudioComponent.generated.h"

/**
 * UAshenDiegeticInnerWorldAudioComponent
 * Audio component modulating disorienting vision blur SFX, memory battle silver chimes, and shadow choir whispers.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticInnerWorldAudioComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDiegeticInnerWorldAudioComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Audio")
	float InnerWorldTransitionVolume = 0.90f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void TriggerInnerWorldTransitionAudio();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void TriggerEldrinMemoryChimeAudio();
};
