// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Memory/AshenMemoryPalaceGraphTypes.h"
#include "AshenMemoryPalaceLocusActor.generated.h"

/**
 * AAshenMemoryPalaceLocusActor
 * 3D interactive Mindscape locus actor projecting historical memory echoes and anchoring psychic branches.
 */
UCLASS()
class ASHENOATH_API AAshenMemoryPalaceLocusActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenMemoryPalaceLocusActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Memory")
	FMemoryGraphNode LocusNodeData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Memory")
	float InteractionRadius = 400.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Memory")
	bool InteractWithLocus(AActor* InteractingPlayer);
};
