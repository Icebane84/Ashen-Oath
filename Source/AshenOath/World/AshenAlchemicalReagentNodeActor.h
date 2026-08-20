// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Crafting/AshenAlchemicalCraftingTypes.h"
#include "AshenAlchemicalReagentNodeActor.generated.h"

/**
 * AAshenAlchemicalReagentNodeActor
 * 3D world harvestable actor representing blighted flora, resin vents, or crystal clusters yielding alchemical crafting reagents.
 */
UCLASS()
class ASHENOATH_API AAshenAlchemicalReagentNodeActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenAlchemicalReagentNodeActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Reagents")
	EAlchemicalReagent ReagentType = EAlchemicalReagent::GloomwoodSap;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Reagents")
	bool bIsEliteNode = false;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Reagents")
	bool bIsHarvested = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Reagents")
	int32 HarvestNode(AActor* InstigatingPlayer);
};
