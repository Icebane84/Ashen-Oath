// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenAlchemicalCaltropGridComponent.generated.h"

/**
 * UAshenAlchemicalCaltropGridComponent
 * Evaluates tactical physical caltrop seeding geometry, creating corridor hazards that channel monster pathfinding into Kaelen's defensive arcs.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAlchemicalCaltropGridComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenAlchemicalCaltropGridComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Alchemy")
	int32 ActiveCaltropFieldsCount = 0;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Alchemy")
	void RegisterCaltropFieldSpawned();
};
