// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Memory/AshenMemoryPalaceGraphTypes.h"
#include "AshenMemoryPalaceNodeComponent.generated.h"

/**
 * UAshenMemoryPalaceNodeComponent
 * Component attached to Mindscape memory actors managing local node state, resonance frequency, and psychic link triggers.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMemoryPalaceNodeComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenMemoryPalaceNodeComponent();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Memory")
	FMemoryGraphNode NodeData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Memory")
	float PsychicResonanceFrequency = 432.0f; // Hz

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Memory")
	bool TriggerPsychicLink(AActor* InstigatingPlayer);
};
