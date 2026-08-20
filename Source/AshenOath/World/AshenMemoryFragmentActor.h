// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenMemoryFragmentActor.generated.h"

/**
 * AAshenMemoryFragmentActor
 * World-placed psychic memory fragment emitting Memory Event imprints and lore text upon player interaction.
 */
UCLASS()
class ASHENOATH_API AAshenMemoryFragmentActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenMemoryFragmentActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Memory")
	FName FragmentID = TEXT("Fragment_001");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Memory")
	float ImprintWeight = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Memory")
	bool bRequiresLorekeeper = false;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Memory")
	bool bHasBeenConsumed = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Memory")
	bool InteractWithFragment(AActor* InteractingPlayer, float CompanionTrust);
};
