// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticHallucinationAudioComponent.generated.h"

/**
 * UAshenDiegeticHallucinationAudioComponent
 * Audio component playing reversed whispers, false footsteps, and phantom sword clashes.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticHallucinationAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticHallucinationAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayReversedWhispers();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayPhantomFootsteps(FVector Direction);
};
