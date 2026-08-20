// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenMemoryWeavingTypes.h"
#include "AshenDiegeticWeavingAudioComponent.generated.h"

/**
 * UAshenDiegeticWeavingAudioComponent
 * Plays spatialized sounds: high-tension violin plucks, radiant harmonic chimes, and violent thread snap acoustics.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticWeavingAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticWeavingAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayThreadPluckSFX(float Tension);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayThreadSnapRuptureSFX();
};
