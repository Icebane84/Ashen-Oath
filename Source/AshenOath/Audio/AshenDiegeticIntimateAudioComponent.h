// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticIntimateAudioComponent.generated.h"

/**
 * UAshenDiegeticIntimateAudioComponent
 * Manages intimate headphone channel sound effects: rapid somatic heartbeat, ragged breath, and dark whispers.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticIntimateAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticIntimateAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void UpdateSomaticHeartbeat(float StrainScalar);
};
