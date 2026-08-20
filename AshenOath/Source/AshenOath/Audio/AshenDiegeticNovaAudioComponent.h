// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticNovaAudioComponent.generated.h"

/**
 * UAshenDiegeticNovaAudioComponent
 * Manages guttural heartbeat modulation, parasite whisper layers, and white-flame detonation audio cues.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticNovaAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticNovaAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void UpdateNovaAudioTelemetry(float KaelenCorruption, float SerafinaBurnout, float IntegrationDebt);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayNovaDetonationCue();
};
