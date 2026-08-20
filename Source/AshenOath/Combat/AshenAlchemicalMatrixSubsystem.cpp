// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/AshenAlchemicalMatrixSubsystem.h"

void UAshenAlchemicalMatrixSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	GarrettPouch.BurningSteelOilVials = 4;
	GarrettPouch.GloomwoodDampenerNeedles = 3;
	GarrettPouch.SmokeBalmCharges = 2;
	GarrettPouch.GhostbloomFlares = 3;
	GarrettPouch.CaltropSupply = 5;
	UE_LOG(LogTemp, Log, TEXT("UAshenAlchemicalMatrixSubsystem: Alchemical Matrix Subsystem initialized."));
}
void UAshenAlchemicalMatrixSubsystem::Deinitialize() { Super::Deinitialize(); }

bool UAshenAlchemicalMatrixSubsystem::CraftAlchemicalMatrix(EAlchemicalMatrixType Type, int32 Quantity)
{
	switch (Type)
	{
	case EAlchemicalMatrixType::BurningSteelOil:
		GarrettPouch.BurningSteelOilVials += Quantity;
		break;
	case EAlchemicalMatrixType::GloomwoodDampener:
		GarrettPouch.GloomwoodDampenerNeedles += Quantity;
		break;
	case EAlchemicalMatrixType::SulfurousSmokeBalm:
		GarrettPouch.SmokeBalmCharges += Quantity;
		break;
	case EAlchemicalMatrixType::GhostbloomFlashFlare:
		GarrettPouch.GhostbloomFlares += Quantity;
		break;
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenAlchemicalMatrixSubsystem: Crafted %d of Matrix Type %d."),
		Quantity, static_cast<int32>(Type));
	return true;
}

bool UAshenAlchemicalMatrixSubsystem::ConsumeAlchemicalMatrix(EAlchemicalMatrixType Type)
{
	switch (Type)
	{
	case EAlchemicalMatrixType::BurningSteelOil:
		if (GarrettPouch.BurningSteelOilVials <= 0) return false;
		GarrettPouch.BurningSteelOilVials--;
		break;
	case EAlchemicalMatrixType::GloomwoodDampener:
		if (GarrettPouch.GloomwoodDampenerNeedles <= 0) return false;
		GarrettPouch.GloomwoodDampenerNeedles--;
		break;
	case EAlchemicalMatrixType::SulfurousSmokeBalm:
		if (GarrettPouch.SmokeBalmCharges <= 0) return false;
		GarrettPouch.SmokeBalmCharges--;
		break;
	case EAlchemicalMatrixType::GhostbloomFlashFlare:
		if (GarrettPouch.GhostbloomFlares <= 0) return false;
		GarrettPouch.GhostbloomFlares--;
		break;
	}

	UE_LOG(LogTemp, Log, TEXT("UAshenAlchemicalMatrixSubsystem: Consumed Matrix Type %d."), static_cast<int32>(Type));
	return true;
}
