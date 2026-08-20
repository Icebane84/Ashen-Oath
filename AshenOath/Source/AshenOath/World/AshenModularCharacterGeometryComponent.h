// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenModularCharacterGeometryComponent.generated.h"

/**
 * UAshenModularCharacterGeometryComponent
 * Component managing modular character geometry mesh separation rules to prevent vertex clipping during combat rolls, parries, and jump strikes.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenModularCharacterGeometryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenModularCharacterGeometryComponent();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Geometry")
	bool bModularSeamsEnforced = true;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Geometry")
	bool VerifyMeshSeamIntegrity();
};
