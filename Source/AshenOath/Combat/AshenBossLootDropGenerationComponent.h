// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenBossLootDropGenerationComponent.generated.h"

/**
 * UAshenBossLootDropGenerationComponent
 * Drops Eldrin memory shards and radiant inquisitorial relics upon boss death.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBossLootDropGenerationComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenBossLootDropGenerationComponent();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Loot")
	int32 GuaranteedMemoryShards = 3;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Loot")
	int32 GenerateBossLootDrops();
};
