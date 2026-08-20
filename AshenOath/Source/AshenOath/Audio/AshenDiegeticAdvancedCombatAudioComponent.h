// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDiegeticAdvancedCombatAudioComponent.generated.h"

/**
 * UAshenDiegeticAdvancedCombatAudioComponent
 * Sharp steel deflection ring, unchained berserk blood-rush heartbeat, void rupture low-frequency bass drop.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticAdvancedCombatAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticAdvancedCombatAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayParryDeflectionRing();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayUnchainedBloodRushPulse();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayVoidShatterBassDrop();
};
