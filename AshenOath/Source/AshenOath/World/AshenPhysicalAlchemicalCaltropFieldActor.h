// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenPhysicalAlchemicalCaltropFieldActor.generated.h"

/**
 * AAshenPhysicalAlchemicalCaltropFieldActor
 * 3D world actor placing physical sharp caltrops that ignite upon kinetic impact, stripping 15% armor from enemies.
 */
UCLASS()
class ASHENOATH_API AAshenPhysicalAlchemicalCaltropFieldActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenPhysicalAlchemicalCaltropFieldActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Alchemy")
	bool bIsFieldIgnited = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Alchemy")
	void TriggerKineticIgnition();
};
