// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenTrioPartySpawnerComponent.generated.h"

class AAshenSerafinaCompanionCharacter;
class AAshenGarrettCompanionCharacter;

/**
 * UAshenTrioPartySpawnerComponent
 * Spawns Serafina and Garrett on Kaelen's left and right flanks upon BeginPlay, linking the trio's formation.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTrioPartySpawnerComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenTrioPartySpawnerComponent();

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Spawner")
	TSubclassOf<AAshenSerafinaCompanionCharacter> SerafinaClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Spawner")
	TSubclassOf<AAshenGarrettCompanionCharacter> GarrettClass;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Spawner")
	AAshenSerafinaCompanionCharacter* SpawnedSerafina;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Spawner")
	AAshenGarrettCompanionCharacter* SpawnedGarrett;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Spawner")
	bool SpawnTrioCompanions();
};
