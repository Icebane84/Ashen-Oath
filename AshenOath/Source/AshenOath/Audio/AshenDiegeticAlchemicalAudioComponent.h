// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenAlchemicalFormulationTypes.h"
#include "AshenDiegeticAlchemicalAudioComponent.generated.h"

/**
 * UAshenDiegeticAlchemicalAudioComponent
 * Plays spatialized sounds for glass reagent vials clinking, oil ignition whooshes, and magnesium flash bangs.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDiegeticAlchemicalAudioComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenDiegeticAlchemicalAudioComponent();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Audio")
	void PlayAlchemicalSound(EAlchemicalMatrixType Type);
};
