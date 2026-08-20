// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCompassionateParasiteAudioComponent.generated.h"

/**
 * UAshenCompassionateParasiteAudioComponent
 * Audio component evaluating player combat habits (Martyr's Guard, Serafina protection) to voice tailored compassionate parasite whispers during crisis dilation.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompassionateParasiteAudioComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompassionateParasiteAudioComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Audio")
	float ParasiteWhisperVolume = 0.90f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void TriggerTailoredParasiteWhisper(FName HabitContext);
};
